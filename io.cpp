#include <iostream>

#include "source.h"

using namespace std;

void readInputs(const string &filename, vector<Pizza>& pizzas, Team& teams)
{
    freopen(filename.c_str(), "r", stdin);

    int numberOfPizzas;
    cin >> numberOfPizzas >> teams.numberTeam2 >> teams.numberTeam3 >> teams.numberTeam4;

    for (int i = 0; i < numberOfPizzas; ++i)
    {
        pizzas.push_back(Pizza{i, {}, {}});
    }

    for (int i = 0; i < numberOfPizzas; ++i)
    {
        int numberOfIngredients;
        cin >> numberOfIngredients;

        vector<string> ingredients(numberOfIngredients);
        for (int j = 0; j < numberOfIngredients; ++j)
        {
            cin >> ingredients[j];
            if (ingredientIndex.find(ingredients[j]) == ingredientIndex.end())
            {
                ingredientIndex[ingredients[j]] = ingredientIndex.size();
            }
        }
        pizzas[i].ingredients = ingredients;
    }

    for (int i = 0; i < numberOfPizzas; ++i)
    {
        for (auto ingredient : pizzas[i].ingredients)
        {
            pizzas[i].ingredientsBitSet.set(ingredientIndex[ingredient]);
        }
    }
}



void writeOutputs(const string& filename, const vector<Delivery>& deliveries)
{
    freopen(filename.c_str(), "w", stdout);

    cout << deliveries.size() << "\n";
    for(auto delivery: deliveries)
    {
        cout << delivery.teamId;
        for (auto pizzaId : delivery.pizzaIds)
        {
            cout << " " << pizzaId;
        }
        cout << "\n";
    }
}

// unordered_map<string, vector<int>> ingredientToPizzas




int main()
{
    vector<Pizza> pizzas;
    Team teams;
    
    readInputs("a_example", pizzas, teams);

    cout << "Team2: " << teams.numberTeam2 << "\n";
    cout << "Team3: " << teams.numberTeam3 << "\n";
    cout << "Team4: " << teams.numberTeam4 << "\n";

    for (auto pizza : pizzas)
    {
        cout << "--\n";
        for (auto ingredient : pizza.ingredients)
        {
            cout << ingredient << " ";
        }
        cout << "\n";
        cout << pizza.ingredientsBitSet << "\n";
    }

    cout << "\n\n";

    sortPizzasWithIngredients(pizzas);

    for(auto pizza: pizzas)
    {
        cout << "--\n";
        for(auto ingredient: pizza.ingredients)
        {
            cout << ingredient << " ";
        }
        cout << "\n";
        cout << pizza.ingredientsBitSet << "\n";
    }


        // vector<Delivery> deliveries {
        //     {2, {1, 4}},
        //     {3, {0, 2, 3}}
        // };

        // writeOutputs("result", deliveries);

        return 0;
}

