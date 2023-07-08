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
namespace example {
class Transport {
 public:
  enum class Status : int {
    done = 0,
    wip,
    waiting,
    problem
  };

  virtual void deliver() = 0;
  virtual std::string send_message() const = 0;
  virtual ~Transport() {}

  Status status() const {
    return this->status_;
  }

  std::string address() {
    return this->address_;
  }

  Transport(const std::string& address) :
    address_(address), status_(Status::waiting) {}

 protected:
  std::string address_;
  Status status_;
};

class Truck : public Transport {
 public:
  void deliver() override {
    this->status_ = Status::problem;
    std::cout << "Deliver on road with truck." << std::endl;
  }
  std::string send_message() const override {
    return "Some problems occure on the road.";
  }

  std::string phone_number() const {
    return this->phone_number_;
  }

  Truck(const std::string&address, const std::string&phone_number) :
    Transport(address), phone_number_(phone_number) {}

 private:
  std::string phone_number_;
};

class Ship : public Transport {
 public:
  void deliver() override {
    this->status_ = Status::wip;
    std::cout << "Deliver on road with ship." << std::endl;
  }

  std::string send_message() const override {
    return "Sea is good condition.";
  }

  std::string country() {
    return this->country_;
  }

  std::string port() {
    return this->port_;
  }

  Ship(const std::string& address, const std::string& country, const std::string& port) :
    Transport(address), country_(country), port_(port) {}

 private:
  std::string country_;
  std::string port_;
};

class Logistics {
 public:
  virtual void factory_method() = 0;
  virtual ~Logistics() {}

  void delivery() {
    this->transport_->deliver();
  }
  void message() {
    auto message = this->transport_->send_message();
    auto status = this->transport_->status();
    auto address = this->transport_->address();

    std::cout << "Delivery to " << address << std::endl;
    std::cout << "NOW STATUS: " << (int)status << std::endl;
    std::cout << message << std::endl;
    std::cout << std::endl;
  }

 protected:
  std::unique_ptr<Transport> transport_;
};

class RoadLogistics : public Logistics {
 public:
  void factory_method() override {
    this->transport_ = std::make_unique<Truck>("tokyo", "xxx-xxx-xxx");
  }
};

class SeaLogistics : public Logistics {
 public:
  void factory_method() override {
    this->transport_ = std::make_unique<Ship>("tokyo", "Japan", "Yaezu");
  }
};
};  // namespace example

/**
 * @brief Entry point from main.cc
*/
void execute();
}  // namespace factory_method

#endif  // SRC_FACTORY_METHOD_FACTORY_METHOD_HH_
