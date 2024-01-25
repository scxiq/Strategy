#include <iostream>
#include <memory>

// Інтерфейс стратегії
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() = default;
};

// Конкретна стратегія 1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 1\n";
    }
};

// Конкретна стратегія 2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 2\n";
    }
};

// Контекст, який використовує стратегію
class Context {
public:
    Context(std::shared_ptr<Strategy> strategy) : strategy_(strategy) {}

    void setStrategy(std::shared_ptr<Strategy> strategy) {
        strategy_ = strategy;
    }

    void executeStrategy() {
        strategy_->execute();
    }

private:
    std::shared_ptr<Strategy> strategy_;
};

int main() {
    // Використання паттерна "Стратегія"
    std::shared_ptr<ConcreteStrategy1> strategy1 = std::make_shared<ConcreteStrategy1>();
    std::shared_ptr<ConcreteStrategy2> strategy2 = std::make_shared<ConcreteStrategy2>();

    Context context(strategy1);

    // Використання першої стратегії
    context.executeStrategy();

    // Зміна стратегії
    context.setStrategy(strategy2);

    // Використання другої стратегії
    context.executeStrategy();

    return 0;
}
