#pragma once

#include <string>

enum class OrderBookType
{
  bid,
  ask,
  asksale,
  bidsale,
  unknown
};

class OrderBookEntry
{
public:
  OrderBookEntry(double price,
                 double amount,
                 std::string timestamp,
                 std::string product,
                 OrderBookType orderType,
                 std::string username = "dataset");

  static OrderBookType stringToOrderBookType(std::string s);

  static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
  {
    return e1.timestamp < e2.timestamp;
  };

  static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
  {
    return e1.price < e2.price;
  };

  static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
  {
    return e1.price > e2.price;
  };


  double price;
  double amount;
  std::string timestamp;
  std::string product;
  OrderBookType orderType;
  std::string username;
};