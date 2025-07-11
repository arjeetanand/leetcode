class Solution {
public:
    typedef pair<long long, int> RoomStatus;

    int mostBooked(int totalRooms, vector<vector<int>>& sessions) {
        int sessionCount = sessions.size();

        // Sort sessions based on their start times
        sort(sessions.begin(), sessions.end());

        // Track how many times each room is assigned
        vector<int> roomFrequency(totalRooms, 0);

        // Min-heap to store busy rooms: {freeAtTime, roomId}
        priority_queue<RoomStatus, vector<RoomStatus>, greater<RoomStatus>> occupied;

        // Min-heap for all free room numbers (lowest number gets priority)
        priority_queue<int, vector<int>, greater<int>> available;

        // Initially, all rooms are free
        for (int id = 0; id < totalRooms;) {
            available.push(id++);
        }

        for (const auto& slot : sessions) {
            int begin = slot[0];
            int finish = slot[1];

            // Free up rooms that are done by the current start time
            while (!occupied.empty() && occupied.top().first <= begin) {
                int freedRoom = occupied.top().second;
                occupied.pop();
                available.push(freedRoom);
            }

            if (!available.empty()) {
                int chosenRoom = available.top();
                available.pop();
                occupied.push({finish, chosenRoom});
                roomFrequency[chosenRoom]++;
            } else {
                // No room is free now, wait for the earliest one to get free
                auto [nextFree, roomId] = occupied.top();
                occupied.pop();
                long long adjustedEnd = nextFree + (finish - begin);
                occupied.push({adjustedEnd, roomId});
                roomFrequency[roomId]++;
            }
        }

        // Find the room with the highest usage
        int mostUsedRoom = 0;
        for (int id = 1; id < totalRooms; id++) {
            if (roomFrequency[id] > roomFrequency[mostUsedRoom]) {
                mostUsedRoom = id;
            }
        }

        return mostUsedRoom;
    }
};