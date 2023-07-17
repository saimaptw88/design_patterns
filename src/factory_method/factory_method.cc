// Copyright 2023 saito
#include "../../src/factory_method/factory_method.hh"


namespace factory_method {
int sum(int a, int b) {
  return a + b;
}

std::string ConcreteProduct1::Operation() const {
  return "{Result of the ConcreteProduct1}";
}

std::string ConcreteProduct2::Operation() const {
  return "{Result of the ConcreteProduct2}";
}

std::string Creator::SomeOperation() const {
  std::unique_ptr<Product> product(this->FactoryMethod());

  std::string result = "Creator: The same creator's code has just worked with"
                     + product->Operation();

  return result;
}

std::unique_ptr<Product> ConcreteCreator1::FactoryMethod() const {
  return std::make_unique<ConcreteProduct1>();
}

std::unique_ptr<Product> ConcreteCreator2::FactoryMethod() const {
  return std::make_unique<ConcreteProduct2>();
}

void ClientCode(std::unique_ptr<Creator> creator) {
  std::cout << "Client: I'm not aware of creator's class, but it still works\n"
            << creator->SomeOperation()
            << std::endl;
}

namespace Example {
std::string Track::deliver() const {
  return "Deliver by Track";
}

std::string Ship::deliver() const {
  return "Deliver by Ship";
}

std::string AirPlane::deliver() const {
  return "Deliver by Airplane";
}

void Logistics::send() const {
  Transport* transport = this->createTransport();
  std::cout << transport->deliver() << std::endl;

  delete transport;
}

Transport* LoadLogistics::createTransport() const {
  return new Track;
}

Transport* SeaLogistics::createTransport() const {
  return new Ship;
}

Transport* SkyLogistics::createTransport() const {
  return new AirPlane;
}
};  // namespace Example

void execute() {
  std::cout << "****** Factory Method *****" << std::endl;
  std::cout << "App: Launched with the ConcreteCreator1."
            << std::endl;

  std::unique_ptr<Creator> creator1(new ConcreteCreator1());
  ClientCode(std::move(creator1));

  std::cout << std::endl;

  std::cout << "App: Launched with the ConcreteCreator2."
            << std::endl;

  std::unique_ptr<Creator> creator2(new ConcreteCreator2());
  ClientCode(std::move(creator2));

  std::cout << std::endl;

  Example::LoadLogistics load;
  Example::SeaLogistics sea;
  Example::SkyLogistics sky;

  load.send();
  sea.send();
  sky.send();
}
}  // namespace factory_method
