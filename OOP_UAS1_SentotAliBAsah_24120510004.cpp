#include <iostream>
#include <string>
#include <vector>

// ========================== //
// Base class: Person //
// ========================== //
class Person {
public:
    Person(std::string id, std::string name, std::string email): 
    id_(std::move(id)), 
    name_(std::move(name)), 
    email_(std::move(email)) {}

    std::string getName() const { return name_; }

protected:
    std::string id_;
    std::string name_;
    std::string email_;
};

// ========================== //
// Subclas: Player //
// ========================== //
class Player : public Person {
public:
    Player(std::string id, std::string name, std::string email, std::string position)
        : Person(std::move(id), std::move(name), std::move(email)), position_(std::move(position)) {}

private:
    std::string position_;
};

// ========================== //
// Subclass:  coach //
// ========================== //
class Coach : public Person {
public:
    Coach(std::string id, std::string name, std::string email, std::string role)
        : Person(std::move(id), std::move(name), std::move(email)), role_(std::move(role)) {}

    void introduce() const {
        std::cout << "- " << role_ << ": " << name_ << "\n";
    }

private:
    std::string role_;
};

// ========================== ///
// Entitiy: Team //
// ========================== //
class Team {
public:
    Team(std::string name, std::string division)
        : name_(std::move(name)), division_(std::move(division)) {}

    void addPlayer(const Player& player) {
        players_.push_back(player);
    }

    void addCoach(const Coach& coach) {
        coaches_.push_back(coach);
    }

    void printRoster() const {
        std::cout << "\nClub: FC Cakrawala\n";
        std::cout << "Team: " << name_ << " (" << division_ << ")\n";

        std::cout << "\nCoaches:\n";
        for (const auto& coach : coaches_) {
            coach.introduce();
        }

        std::cout << "\nPlayers:\n";
        for (const auto& player : players_) {
            std::cout << "- " << player.getName() << "\n";
        }
    }



private:
    std::string name_;
    std::string division_;
    std::vector<Coach> coaches_;
    std::vector<Player> players_;
};

// ========================== //
// Main Fanction //
// ========================== //

int main() {
    Team teamU23("FC Cakrawala Muda", "U-23");

    // Tambahkan Head Coach daan Assistantt Coach
    Coach headCoach(
        "C001", "Sentot Ali Basah - 24120510004", "sentot@cakrawala.ac.id", "Head Coach"
    );
    Coach assistantCoach(
        "C002", "Riyo Urda", "riyo@cakrawala.ac.id", "Assistant Coach"
    );
    teamU23.addCoach(headCoach);
    teamU23.addCoach(assistantCoach);

    // Tambahkan 15 pemain mahasiwa
    for (int i = 1; i <= 15; ++i) {
        std::string id     = "P" + std::to_string(i);
        std::string name   = "Mahasiswa" + std::to_string(i);
        std::string email  = "mhs" + std::to_string(i) + "@cakrawala.ac.id";
        std::string posisi = "Midfielder";
        teamU23.addPlayer(
            Player(
                id, 
                name, 
                email, 
                posisi
            ));
    }

   // Tampilkan daftar lengkap tim
teamU23.printRoster();

return 0;
}
