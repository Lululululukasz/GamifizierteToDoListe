//
// Created by Jan Ole Weighardt on 10.05.23.
//

#include "Task.h"
#include "iostream"
#include <random>
using namespace std;

namespace ToDoListAdventure {
    void Tasks::newTask(std::string const &task) {
        // Add new tasks to the vector
        this->task.emplace_back(task);
    }

    void Tasks::showTask() {
        for (const auto &element: task) {
            cout << element << endl << endl;
        }
    }

    shared_ptr<string> Tasks::searchTask() {
        std::string input;
        std::cout << "Geben Sie einen Suchbegriff ein: ";
        std::cin >> input;
        return searchTask(input);
    }

    shared_ptr<string> Tasks::searchTask(std::string const &searchIn) { // TODO: Optimierung Levenshtein Algorithmus
        auto it = std::find(task.begin(), task.end(), searchIn);
        if (it != task.end()) {
            std::cout << "Task: " << *it << std::endl;
            return std::make_shared<string>( *it);
        } else {
            std::cout << "Ein Task mit diesem Namen existiert nicht, bitte den richtigen Tasknamen eingeben"
                      << std::endl;
            return nullptr;
        }
    }

    void Tasks::deleteTask() {
            string taskToDelete;
            std::cout << "Geben sie die Task ein die sie entfernen wollen: ";
            std::cin >> taskToDelete;

            auto it = std::find(task.begin(), task.end(), taskToDelete);
            if (it != task.end()) {
                task.erase(it);
                std::cout << "Task entfernt!" << std::endl;
            } else {
                std::cout << "Ein Task mit diesem Namen existiert nicht, bitte den richtigen Tasknamen eingeben"
                          << std::endl;
            }
    }

   string Tasks::suggestTask(){
        int min {0}, max {static_cast<int>(defaultTask.size()) -1}, zwischenspeicher;
       std::random_device rd;
       std::default_random_engine eng(rd());
       uniform_int_distribution<int> distr(min, max);
       zwischenspeicher = distr(eng);
        return defaultTask[zwischenspeicher];
    }
    // ToDoListAdventure
}

