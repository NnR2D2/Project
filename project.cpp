// Write a program to manage Food order in a restaurant. In a restaurant, the food order
// contains food number, size, and quantity. The order is served in the form of first come
// first serve basis. You program will display total number of orders received, served and
// waiting at any point in time.


#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

struct FoodItem
{
  int number;
  string name;
  vector<int> sizes;
};

struct FoodOrder
{
  int number;
  string size;
  int quantity;
};

int calculatePrice(const FoodItem &item, const string &size, const int quantity)
{
  int price = 0;
  if (size == "S"||size=="s")
  {
    price = item.sizes[0] * quantity;
  }
  else if (size == "M"||size=="m")
  {
    price = item.sizes[1] * quantity;
  }
  else if (size == "L"||size=="l")
  {
    price = item.sizes[2] * quantity;
  }
  return price;
}

int main()
{
  queue<FoodOrder> orderQueue;
  vector<FoodItem> menu = {
      {1, "Burger", {100, 150, 200}},
      {2, "Pizza", {400, 500, 600}},
      {3, "Fries", {50, 75, 100}},
      {4, "Salad", {100, 150, 200}},
      {5, "Sandwich", {80, 120, 160}},
      {6, "Pasta", {200, 250, 300}},
      {7, "Shrimp", {300, 400, 500}},
      {8, "Steak", {500, 600, 700}},
      {9, "Chicken", {150, 200, 250}},
      {10, "Fish", {200, 250, 300}}};
  int totalOrders = 0;
  int ordersServed = 0;
  int totalRevenue = 0;
  vector<FoodOrder> ordersPlaced;
  while (true)
  {
    cout << "\nWhat would you like to do?\n";
    cout << "1. Place a new order\n";
    cout << "2. Serve the next order\n";
    cout << "3. Display current order status\n";
    cout << "4. Quit\n";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {

      string choice = "Y";
      while (choice == "Y" || choice == "y")
      {
        cout << "\nOur menu:\n";
        cout << "#   Item Name\n";
        for (const auto &item : menu)
        {
          cout << item.number << ".  " << item.name << endl;
        }
        cout << "\nPlease select an item from the menu:";
        int number;
        cin >> number;
        bool found = false;
        for (const auto &item : menu)
        {
          if (item.number == number)
          {
            found = true;
            cout << "\nSizes available (S/M/L): ";
            string size;
            cin >> size;
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            FoodOrder order = {number, size, quantity};
            orderQueue.push(order);
            ordersPlaced.push_back(order);
            totalOrders++;
            cout << "\nYour " << item.name << " (Size: " << size << ", Quantity: " << quantity << ") has been added to the queue. Do you want to place another order? (Y/N)\n";
            cin >> choice;
            break;
          }
        }
        if (!found)
        {
          cout << "\nInvalid food item number. Please try again.\n";
        }
      }
      break;
    }
    case 2:
    {
      if (orderQueue.empty())
      {
        cout << "\nThere are no orders waiting at the moment. Please place a new order.\n";
      }
      else
      {
        FoodOrder nextOrder = orderQueue.front();
        int price = calculatePrice(menu[nextOrder.number - 1], nextOrder.size, nextOrder.quantity);
        cout << "\nServing order " << ++ordersServed << ": " << menu[nextOrder.number - 1].name << " (Size: " << nextOrder.size << ", Quantity: " << nextOrder.quantity << "), Total Price: " << price << " Taka" << endl;
        orderQueue.pop();
        totalRevenue += price;
      }
      break;
    }
    case 3:
    {
      cout << "\nCurrent Order Status:\n";
      cout << "Total orders received so far: " << totalOrders << endl;
      cout << "Number of orders served: " << ordersServed << endl;
      cout << "Number of orders waiting to be served: " << orderQueue.size() << endl;
      cout << "Total revenue: " << totalRevenue << " Taka" << endl;
      break;
    }
    case 4:
      cout << "\nThank you for visiting our restaurant. Have a nice day ." << endl;
      return 0;
    default:
      cout << "\nInvalid option. Please try again.\n";
      break;
    }
  }

  return 0;
}
