#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ==========================
// Abstract class: Person
// ==========================
class Person {
public:
    Person(std::string id, std::string name, std::string email) : 
    id_(std::move(id)), 
    name_(std::move(name)), 
    email_(std::move(email)) {}

    virtual void introduce() const = 0;
    virtual ~Person() = default;

    std::string getName() const { return name_; }

protected:
    std::string id_;
    std::string name_;
    std::string email_;
};

// ==========================
// Concrete subclasses
// ==========================
class Player : public Person {
public:
    Player(std::string id, std::string name, std::string email, std::string position)
        : Person(std::move(id), std::move(name), std::move(email)), position_(std::move(position)) {}

    void introduce() const override {
        std::cout << "- Player: " << name_ << " (" << position_ << ")\n";
    }

private:
    std::string position_;
};

class Coach : public Person {
public:
    Coach(std::string id, std::string name, std::string email, std::string role)
        : Person(std::move(id), std::move(name), std::move(email)), role_(std::move(role)) {}

    void introduce() const override {
        std::cout << "- " << role_ << ": " << name_ << "\n";
    }

private:
    std::string role_;
};

class Staff : public Person {
public:
    Staff(std::string id, std::string name, std::string email, std::string duty)
        : Person(std::move(id), std::move(name), std::move(email)), duty_(std::move(duty)) {}

    void introduce() const override {
        std::cout << "- Staff: " << name_ << " (" << duty_ << ")\n";
    }

private:
    std::string duty_;
};

// ==========================
// abstract Factory
// ==========================
class PersonFactory {
public:
    virtual std::unique_ptr<Person> createPerson() const = 0;
    virtual ~PersonFactory() = default;
};

// ==========================
// Concerete Factories
// ==========================
class PlayerFactory : public PersonFactory {
public:
    PlayerFactory(std::string id, std::string name, std::string email, std::string position) : 
    id_(id), 
    name_(name), 
    email_(email), 
    position_(position) {}

    std::unique_ptr<Person> createPerson() const override {
        return std::make_unique<Player> (
        id_, 
        name_, 
        email_, 
        position_
    );
    }

private:
    std::string 
    id_, 
    name_, 
    email_, 
    position_;
};

class CoachFactory : public PersonFactory {
public:
    CoachFactory(std::string id, std::string name, std::string email, std::string role)
        : id_(id), name_(name), email_(email), role_(role) {}

    std::unique_ptr<Person> createPerson() const override {
        return std::make_unique<Coach> (
            id_, 
            name_, 
            email_, 
            role_
        );
    }

private:
    std::string 
    id_, 
    name_, 
    email_, 
    role_;
};

class StaffFactory : public PersonFactory {
public:
    StaffFactory(std::string id, std::string name, std::string email, std::string duty)
        : id_(id), name_(name), email_(email), duty_(duty) {}

    std::unique_ptr<Person> createPerson() const override {
        return std::make_unique<Staff>(id_, name_, email_, duty_);
    }

private:
    std::string 
    id_, 
    name_, 
    email_, 
    duty_;
};

// ==========================
// Eentity: Team
// ==========================
class Team {
public:
    Team(std::string name, std::string division)
        : name_(std::move(name)), division_(std::move(division)) {}

    void addMember(std::unique_ptr<Person> person) {
        roster_.push_back(std::move(person));
    }

    void printRoster() const {
        std::cout << "\nClub: FC Cakrawala\n";
        std::cout << "Team: " << name_ << " (" << division_ << ")\n";

        std::cout << "\nMembers:\n";
        for (const auto& member : roster_) {
            member->introduce();
        }
    }

private:
    std::string name_;
    std::string division_;
    std::vector<std::unique_ptr<Person>> roster_;
};

// ==========================
// Main Function
// ==========================
int main() {
    Team teamU23("FC Cakrawala Muda", "U-23");

    // Tambahkan Head Coach dan Assistant Coach menggunakkan Factory
    CoachFactory headFactory("C001", "Sentot Ali Basah - 24120510004", "sentot@cakrawala.ac.id", "Head Coach");
    CoachFactory assistantFactory("C002", "Riyo Urda", "riyo@cakrawala.ac.id", "Assistant Coach");

    teamU23.addMember(headFactory.createPerson());
    teamU23.addMember(assistantFactory.createPerson());

    // tambahkan 15 pemain mahasiwa melalui PlayerFactory
    for (int i = 1; i <= 15; ++i) {
        std::string id     = "P" + std::to_string(i);
        std::string name   = "Mahasiswa" + std::to_string(i);
        std::string email  = "mhs" + std::to_string(i) + "@cakrawala.ac.id";
        std::string posisi = "Midfielder";

        PlayerFactory pf(id, name, email, posisi);
        teamU23.addMember(pf.createPerson());
    }

    // menampilkan roster
    teamU23.printRoster();

    return 0;
}
