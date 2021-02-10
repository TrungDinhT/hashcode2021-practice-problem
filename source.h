#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>

#include <algorithm>

using namespace std;

constexpr int N = 7;

struct Pizza 
{
    int id;
    vector<string> ingredients;
    bitset<N> ingredientsBitSet;
};

unordered_map<string, vector<int>> ingredientToPizzas; 

unordered_map<string, int> ingredientIndex;

struct Team
{
    int numberTeam2;
    int numberTeam3;
    int numberTeam4;
};

struct Delivery
{
    int teamId;
    vector<int> pizzaIds;
};


int diffIngredients(const Pizza& pizza1, const Pizza& pizza2, bitset<N>& unionIngredients)
{
    unionIngredients = pizza1.ingredientsBitSet & pizza2.ingredientsBitSet;
    return unionIngredients.count();
} 

void sortPizzasWithIngredients(vector<Pizza>& pizzas)
{
    sort(pizzas.begin(), pizzas.end(),
         [](const Pizza &pizza1, const Pizza &pizza2) -> bool {
             return pizza1.ingredientsBitSet.count() > pizza2.ingredientsBitSet.count();
         });
}



auto searchPair(const Pizza& pizza, const vector<Pizza>& pizzas, bitset<N>& unionIngredients)
{
    auto it = pizzas.begin();
    int max = 0;
    for(int i = 0; i < pizzas.size(); i++)
    {
        int diff = diffIngredients(pizza, pizzas[i], unionIngredients);
        if (diff > max)
        {
            max = diff;
            it = pizzas.begin() + i;
        }
        if (max >= pizza.ingredientsBitSet.count() + pizzas[i].ingredientsBitSet.count())
        {
            break;
        }
    }
     
    return it;
}






// int score()

