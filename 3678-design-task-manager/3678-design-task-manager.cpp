#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    // Maps taskId → (userId, priority)
    unordered_map<int, pair<int, int>> taskInfo;

    // Max-heap of (priority, taskId, userId)
    priority_queue<tuple<int, int, int>> maxHeap;

public:
    TaskManager(vector<vector<int>>& initialTasks) {
        for (auto& task : initialTasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        maxHeap.emplace(priority, taskId, userId);
    }

    void edit(int taskId, int newPriority) {
        if (!taskInfo.count(taskId))
            return;

        int userId = taskInfo[taskId].first;
        taskInfo[taskId] = {userId, newPriority};
        maxHeap.emplace(newPriority, taskId,
                        userId); // old version stays (lazy deletion)
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy removal
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId, userId] = maxHeap.top();
            maxHeap.pop();

            // Check if task is still valid
            auto it = taskInfo.find(taskId);
            if (it != taskInfo.end() && it->second.first == userId &&
                it->second.second == priority) {
                taskInfo.erase(taskId); // Remove executed task
                return userId;
            }
        }

        return -1; // No tasks available
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */