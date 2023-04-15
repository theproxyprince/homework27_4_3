#pragma once
#include <string>

class Worker {
    class Manager* manager = nullptr;
    std::string currentTask;
public:
    Worker (class Manager* inManager) : manager(inManager) {
        currentTask = "nothing";
    }

    void SetTask(std::string task) {
        currentTask = task;
    }

    std::string GetTask() {
        return currentTask;
    }
};

