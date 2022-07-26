// LeetCode: 2115. Find All Possible Recipes from Given Supplies
// 2115-Find-All-Possible-Recipes-from-Given-Supplies.cpp
// Created by Victor Rogulenko
// July 26, 2022

// You have information about n different recipes. You are given a string array 
// recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], 
// and you can create it if you have all the needed ingredients from ingredients[i]. 
// Ingredients to a recipe may need to be created from other recipes, i.e., 
// ingredients[i] may contain a string that is in recipes.
// You are also given a string array supplies containing all the ingredients that 
// you initially have, and you have an infinite supply of all of them.
// Return a list of all the recipes that you can create. You may return the answer 
// in any order.
// Note that two recipes may contain each other in their ingredients.
// n == recipes.length == ingredients.length
// 1 <= n <= 100
// 1 <= ingredients[i].length, supplies.length <= 100
// 1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
// recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
// All the values of recipes and supplies combined are unique.
// Each ingredients[i] does not contain any duplicate values.

// MAJOR IDEA: Topological sort. For each recipe, iterate over its ingrediends. 
// If we can cook it already move on. If not, look up the recipe of the ingredient and try to cook it (dfs).
// Store thingsWeCanCook and thingsBeingCooked in sets and keep a recipesMap
// Time: O(V+E). Space: O(V)

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findAllRecipes(const std::vector<std::string>& recipes, 
                                       const std::vector<std::vector<std::string>>& ingredients, 
                                       const std::vector<std::string>& supplies) {
        // Build suppliesSet and recipesMap to look up both quickly
        for (const auto& supply : supplies) {
            thingsWeCanCook.insert(supply);
        }
        
        for (int idx = 0; idx < recipes.size(); ++idx) {
            recipesMap[recipes[idx]] = idx;
        }
        
        std::vector<std::string> result;
        
        // Iterate through all recipes and try to cook each      
        for (int idx = 0; idx < recipes.size(); ++idx) {
            if (tryCook(recipes[idx], ingredients)) {
                result.push_back(recipes[idx]);
            }
        }
        return result;
    }
    
private:
    std::unordered_set<std::string> thingsWeCanCook;
    std::unordered_set<std::string> thingsBeingCooked;
    std::unordered_map<std::string, int> recipesMap;
        
    bool tryCook(const std::string& recipe, const std::vector<std::vector<std::string>>& ingredients) {
        // For each recipe, iterate over its ingrediends 
        // If we can cook it already move on. If not, look up the recipe of the ingredient
        // and try to cook it (dfs).
        if (thingsWeCanCook.find(recipe) != thingsWeCanCook.end()) {
            return true;
        }
        if (recipesMap.find(recipe) == recipesMap.end()) {
            return false;
        }
        bool canCook = true;
        thingsBeingCooked.insert(recipe);
        int idx = recipesMap[recipe];
        for (const auto& ingredient : ingredients[idx]) {
            if (thingsWeCanCook.find(ingredient) != thingsWeCanCook.end()) {
                continue;
            }
            if (thingsBeingCooked.find(ingredient) != thingsBeingCooked.end()) {
                canCook = false;
                break;
            }
            if (!tryCook(ingredient, ingredients)) {
                canCook = false;
                break;
            }
        }
        thingsBeingCooked.erase(recipe);
        if (canCook) {
            thingsWeCanCook.insert(recipe);
            return true;
        } else {
            return false;
        }
    }
};

// #bugs = 1