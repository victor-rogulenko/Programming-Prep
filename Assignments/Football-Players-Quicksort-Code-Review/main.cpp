#include <iostream>
#include <vector>
#include <random>  //  std::random_device, std::mt19937
#include <functional>  //  std::less<>()
#include <utility>  //  swap
#include <algorithm> //  std::sort for stress-testing QuickSort

//  DECLARATION
const size_t kMaxTestVector = 5;
const size_t kNumTests = 1000;
const size_t kMaxValue = 10;

struct Player {
    size_t index;
    size_t efficiency;
};

struct MostEffectiveSolidaryTeam {
    std::vector<Player>::iterator first, last;
    size_t efficiency;
};

template <class ForwardIt>
class PartialSumsEfficiency {
public:
    explicit PartialSumsEfficiency(ForwardIt first, ForwardIt last);

    size_t Get(ForwardIt first, ForwardIt last) const;

private:
    std::vector<size_t> data_;
    ForwardIt begin_;
};

//  Reading and Writing
std::vector<Player> ReadAvailablePlayers(std::istream& stream = std::cin);
void PrintTeam(std::vector<Player> team, std::ostream& stream = std::cout);
size_t SumUpEfficiencies(const std::vector<Player>& team);

//  QuickSort
bool CompareIndex(const Player& lhs, const Player& rhs);
bool CompareEfficiency(const Player& lhs, const Player& rhs);

template <class RandomAccessIterator>
RandomAccessIterator PickPivot(RandomAccessIterator first,
                               RandomAccessIterator last,
                               std::mt19937& random_number_generator);

template <class RandomAccessIterator, class Compare>
RandomAccessIterator Partition(RandomAccessIterator first,
                               RandomAccessIterator last,
                               RandomAccessIterator border_iterator,
                               Compare comp = std::less<>());

template <class RandomAccessIterator, class Compare>
void QuickSortRandomized(RandomAccessIterator first,
                         RandomAccessIterator last,
                         std::mt19937& random_number_generator,
                         Compare comp);

template <class RandomAccessIterator, class Compare>
void QuickSort(RandomAccessIterator first, RandomAccessIterator last,
               Compare comp = std::less<>());

//  Actual Solution
template <class ForwardIt, class T, class Compare>
ForwardIt UpperBound(ForwardIt first, ForwardIt last,
                     const T& value, Compare comp = std::less<>());

std::vector<Player> BuildMostEffectiveSolidaryTeam(
    std::vector<Player> players);

//  Stress-Testing
std::vector<Player> DullSolution(std::vector<Player> players);

template <class T>
std::ostream& operator<<(std::ostream& stream,
                         const std::vector<T>& vector);

std::ostream& operator<<(std::ostream& stream, const Player& player);

void StressTestSort();
void StressTestUpperBound();
void StressTestSolution();

//  MAIN
int main() {
//    StressTestSort();
//    StressTestUpperBound();
//    StressTestSolution();
    
    std::vector<Player> players = ReadAvailablePlayers();

    std::vector<Player> final_team = BuildMostEffectiveSolidaryTeam(std::move(players));

    PrintTeam(std::move(final_team));

    return 0;
}

//  IMPLEMENTATION
//  Reading and Writing
std::vector<Player> ReadAvailablePlayers(std::istream& stream) {
    size_t player_count;
    stream >> player_count;
    std::vector<Player> result;
    result.reserve(player_count);
    
    for (size_t it = 0; it < player_count; ++it) {
        Player new_player;
        stream >> new_player.efficiency;
        new_player.index = it + 1;
        
        result.push_back(new_player);
    }
    
    return result;
}

void PrintTeam(std::vector<Player> team, std::ostream& stream) {
    stream << SumUpEfficiencies(team) << "\n";

    QuickSort(team.begin(), team.end(), CompareIndex);
    for (const auto& player : team) {
        stream << player.index << " ";
    }
}

size_t SumUpEfficiencies(const std::vector<Player>& team) {
    size_t total_efficiency = 0;
    for (const auto& player : team) {
        total_efficiency += player.efficiency;
    }
    
    return total_efficiency;
}

//  QuickSort
bool CompareIndex(const Player& lhs, const Player& rhs) {
    return lhs.index < rhs.index;
}

bool CompareEfficiency(const Player& lhs, const Player& rhs) {
    return lhs.efficiency < rhs.efficiency;
}

template <class RandomAccessIterator>
RandomAccessIterator PickPivot(RandomAccessIterator first,
                               RandomAccessIterator last,
                               std::mt19937& random_number_generator) {
    --last;
    const auto distance = std::distance(first, last);
    std::uniform_int_distribution<int> distr(0, distance);
    return std::next(first, distr(random_number_generator));
}

template <class RandomAccessIterator, class Compare>
RandomAccessIterator Partition(RandomAccessIterator first,
                               RandomAccessIterator last,
                               RandomAccessIterator border_iterator,
                               Compare comp) {
    
    if (first + 1 >= last) {
        return first;
    }

    std::swap(*first, *border_iterator);
    const auto start = first;
    
    while (first < last) {
        do {
            --last;
        } while (comp(*start, *last) && first < last);
        
        do {
            ++first;
        } while (comp(*first, *start) && first < last);
        
        if (first < last) {
            std::swap(*first, *last);
        }
    }
    
    std::swap(*start, *last);
    
    return last;
}

template <class RandomAccessIterator, class Compare>
void QuickSortRandomized(RandomAccessIterator first, RandomAccessIterator last,
                         std::mt19937& random_number_generator, Compare comp) {
    
    while (last > first + 1) {
        const auto pivot = PickPivot(first, last, random_number_generator);
        const auto border = Partition(first, last, pivot, comp);
        
        if (std::distance(border, last) >= std::distance(first, border + 1)) {
            QuickSortRandomized(first, border + 1, random_number_generator, comp);
            first = border + 1;
            
        } else {
            QuickSortRandomized(border, last, random_number_generator, comp);
            last = border;
        }
    }
}

template <class RandomAccessIterator, class Compare>
void QuickSort(RandomAccessIterator first, RandomAccessIterator last,
               Compare comp) {
    std::random_device rd;
    std::mt19937 random_number_generator(rd());
    
    QuickSortRandomized(first, last, random_number_generator, comp);
}

//  Actual Solution
template <class ForwardIt>
PartialSumsEfficiency<ForwardIt>::PartialSumsEfficiency(ForwardIt first, ForwardIt last) {
    begin_ = first;
    data_.reserve(std::distance(first, last) + 1);
    size_t current_sum = 0;

    for (auto& it = first; it < last; ++it) {
        current_sum += it->efficiency;
        data_.push_back(current_sum);
    }
}

template <class ForwardIt>
size_t PartialSumsEfficiency<ForwardIt>::Get(ForwardIt first, ForwardIt last) const {

    return data_[std::distance(begin_, last)] - data_[std::distance(begin_, first)]
           + first->efficiency;
}

template <class ForwardIt, class T, class Compare>
ForwardIt UpperBound(ForwardIt first, ForwardIt last,
                     const T& value, Compare comp) {

    auto count = std::distance(first, last);

    while (first != last) {
        const auto step = count / 2;
        const auto middle = std::next(first, step);
        
        if (!comp(value, *middle)) {
            first = middle + 1;
            count -= step + 1;
        } else {
            count = step;
            last = middle;
        }
    }

    return first;
}

std::vector<Player> BuildMostEffectiveSolidaryTeam(std::vector<Player> players) {
    
    QuickSort(players.begin(), players.end(), CompareEfficiency);
    const PartialSumsEfficiency partial_sums(players.begin(), players.end());
    MostEffectiveSolidaryTeam best_team{players.begin(), players.begin()+1, players[0].efficiency};
    
    for (auto current_begin = players.begin(); current_begin < players.end(); ++current_begin) {

        Player current_efficiency_bound{current_begin->index,
                                        current_begin->efficiency};
        if (current_begin + 1 < players.end()) {
            current_efficiency_bound.efficiency += (current_begin + 1)->efficiency;
        }

        // Take one element before UpperBound
        auto current_end = UpperBound(current_begin, players.end(),
                                      current_efficiency_bound,
                                      CompareEfficiency);
        --current_end;

        const size_t current_sum_efficiency = partial_sums.Get(current_begin, current_end);

        if (current_sum_efficiency > best_team.efficiency) {
            best_team = MostEffectiveSolidaryTeam{current_begin, current_end + 1,
                                                  current_sum_efficiency};
        }
    }

    return std::vector<Player>(best_team.first, best_team.last);
}

std::vector<Player> DullSolution(std::vector<Player> players) {
    
    std::sort(players.begin(), players.end(), CompareEfficiency);

    const PartialSumsEfficiency partial_sums(players.begin(), players.end());
    MostEffectiveSolidaryTeam best_team{players.begin(), players.begin()+1, players[0].efficiency};


    for (auto current_begin = players.begin(); current_begin < players.end(); ++current_begin) {

        Player current_efficiency_bound{current_begin->index,
                                        current_begin->efficiency};
        if (current_begin + 1 < players.end()) {
            current_efficiency_bound.efficiency += (current_begin + 1)->efficiency;
        }
        
        auto current_end = current_begin + 1;
        
        while (current_end != players.end() && current_end->efficiency <=
               current_efficiency_bound.efficiency) {
            ++current_end;
        }
        --current_end;

        size_t current_sum_efficiency = partial_sums.Get(current_begin, current_end);
        if (current_sum_efficiency > best_team.efficiency) {
            best_team = MostEffectiveSolidaryTeam{current_begin, current_end + 1,
                                                  current_sum_efficiency};
        }
    }

    std::vector<Player> result(best_team.first, best_team.last);
    return result;
}

template<class T>
std::ostream& operator<<(std::ostream& stream,
                         const std::vector<T>& vector) {
    for (auto it : vector) {
        stream << it << " ";
    }
    stream << "\n";
    return stream;
}

//  Stress-Testing
std::ostream& operator<<(std::ostream& stream, const Player& player) {
    stream << player.efficiency << "\n";
    return stream;
}

void StressTestSort() {
    std::random_device rd;
    std::mt19937 random_number_generator(rd());
    
    for (size_t test = 0; test < kNumTests; ++test) {
        std::vector<size_t> test_vector;
        for (size_t i = 0; i < kMaxTestVector; ++i) {
            std::uniform_int_distribution<int> distr(1, kMaxValue);
            test_vector.push_back(distr(random_number_generator));
        }
        
        std::cerr << "*********** New Test ************* \n";
        std::cerr << test_vector;
        
        std::vector<size_t> expected = test_vector;
        std::vector<size_t> result = test_vector;
        std::sort(expected.begin(), expected.end());
        
        QuickSort(result.begin(), result.end(),
                  [](size_t lhs, size_t rhs){
                      return lhs < rhs;
                  });
        
        if (result != expected) {
            std::cerr << "Test failed\n"
                      << "Expected \n" << expected
                      << "Your result: \n" << result;
            throw std::runtime_error("test failed");
        }
    }
    std::cerr << "QUICKSORT: TESTS PASSED!";
}

void StressTestUpperBound() {
    std::random_device rd;
    std::mt19937 random_number_generator(rd());
    
    for (size_t test = 0; test < kNumTests; ++test) {
        std::vector<size_t> test_vector;
        for (size_t i = 0; i < kMaxTestVector; ++i) {
            std::uniform_int_distribution<int> distr(1, kMaxValue);
            test_vector.push_back(distr(random_number_generator));
        }
    
        std::uniform_int_distribution<size_t> distr(1, kMaxValue);
        int value = distr(random_number_generator);
        
        std::cerr << "*********** New Test ************* \n";
        std::sort(test_vector.begin(), test_vector.end());
        std::cerr << test_vector;
        std::cerr << value << "\n";
        
        auto expected = std::upper_bound(test_vector.begin(),
            test_vector.end(), value);
        auto result = UpperBound(test_vector.begin(),
            test_vector.end(), value, std::less<>());
        
        if (result != expected) {
            std::cerr << "Test failed\n"
                      << "Expected: " << *expected << "\n"
                      << "Your result: " << *result << "\n";
            throw std::runtime_error("test failed");
        }
    }
    std::cerr << "UpperBound: TESTS PASSED!";
}

void StressTestSolution() {
    std::random_device rd;
    std::mt19937 random_number_generator(rd());
    
    for (size_t test = 0; test < kNumTests; ++test) {
        std::vector<Player> players;
        std::uniform_int_distribution<size_t> distr(1, kMaxValue);
        
        for (size_t i = 0; i < kMaxTestVector; ++i) {
            players.emplace_back(Player{i + 1, distr(random_number_generator)});
        }
        
        std::cerr << "*********** New Test ************* \n";
        for (auto player : players) {
            std::cerr << player.efficiency << " ";
        }
        std::cerr << "\n";
        
        auto expected = DullSolution(players);
        auto result = BuildMostEffectiveSolidaryTeam(players);
        
        size_t expected_sum = SumUpEfficiencies(expected);
        size_t result_sum = SumUpEfficiencies(result);
        
        if (result_sum != expected_sum) {
            std::cerr << "Test failed\n";
            std::cerr << "Expected result:\n";
            PrintTeam(expected, std::cerr);
            std::cerr << "Your result:\n";
            PrintTeam(result, std::cerr);
            throw std::runtime_error("test failed");
        }
    }
    std::cerr << "Solution: TESTS PASSED!";
}
