#include <bits/stdc++.h>
using namespace std;

class EventManager {
    // priority , event
    inline static auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
    // event, priority
    unordered_map<int, int> mpp;

  public:
    EventManager(vector<vector<int>> &events) {

        for (auto &e : events) {
            pq.push({e[1], e[0]});
            mpp[e[0]] = e[1];
        }
    }

    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }

    int pollHighest() {
        while (!pq.empty()) {
            auto [prior, event] = pq.top();
            pq.pop();

            if (mpp[event] != prior) {
                continue;
            }

            mpp.erase(event);
            return event;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
