// Copyright 2023 saito
#ifndef SRC_FACTORY_METHOD_FACTORY_METHOD_HH_
#define SRC_FACTORY_METHOD_FACTORY_METHOD_HH_

#include <iostream>
#include <memory>
#include <string>
#include <utility>


/**
 * @brief Factory Method namespace
 * @details Sample code
*/
namespace factory_method {
int sum(int, int);

/**
 * @brief Product interface
 * @details Execute concrete product object methods
*/
class Product {
 public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

/**
 * @brief Concrete Product1
 * @details Execute operation method
*/
class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override;
};

/**
 * @brief Concrete Product2
 * @details Execute operation method
*/
class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override;
};

/**
 * @brief Creator interface
 * @details Execute concrete product methods from this object
*/
class Creator {
 public:
  virtual ~Creator() {}
  virtual std::unique_ptr<Product> FactoryMethod() const = 0;

  std::string SomeOperation() const;
};

/**
 * @brief Concrete Creator1
 * @details This object is used from Product interface
*/
class ConcreteCreator1 : public Creator {
 public:
  std::unique_ptr<Product> FactoryMethod() const override;
};

/**
 * @brief Concrete Creator2
 * @details This object is used from Product interface
*/
class ConcreteCreator2 : public Creator {
 public:
  std::unique_ptr<Product> FactoryMethod() const override;
};

/**
 * @brief Execute by client
 * @details Create creator object and execute concrete product method
*/
void ClientCode(std::unique_ptr<Creator>);

/**
 * @brief Example to help understand this design pattern
 * @details Design transport
*/

namespace Example {
class Transport {
 public:
  virtual std::string deliver() const = 0;
  virtual ~Transport() {};
};

class Track : public Transport {
 public:
  std::string deliver() const override;
};

class Ship : public Transport {
 public:
  std::string deliver() const override;
};

class AirPlane : public Transport {
 public:
  std::string deliver() const override;
};

class Logistics {
 public:
  virtual Transport* createTransport() const = 0;
  virtual ~Logistics() {};

  void send() const;
};

class LoadLogistics : public Logistics {
 public:
  Transport* createTransport() const override;
};

class SeaLogistics : public Logistics {
 public:
  Transport* createTransport() const override;
};

class SkyLogistics : public Logistics {
 public:
  Transport* createTransport() const override;
};
};  // namespace Example

/**
 * @brief Entry point from main.cc
*/
void execute();
}  // namespace factory_method

#endif  // SRC_FACTORY_METHOD_FACTORY_METHOD_HH_
