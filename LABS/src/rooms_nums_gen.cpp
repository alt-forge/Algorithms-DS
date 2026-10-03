#include <set>
#include "rooms_nums_gen.h"

const int N = 300;
int g[N + 2];
int tau[N + 2];
int i = 0;
bool done = false;

void rooms_init() {
    for (int j = 0; j <= N + 1; j++) {
        g[j] = 0;
        tau[j] = j + 1;
    }
    i = 0;
    done = false;
}

std::set<int> nextRooms_nums() {
    std::set<int> rooms;
    if (done) return rooms;

    for (int j = 1; j <= N; j++) {
        if (g[j]) rooms.insert(j);
    }

    int l = tau[0];
    g[i] = 1 - g[i];
    tau[0] = 1;
    if (i > 0) tau[i - 1] = tau[i];
    tau[i] = i + 1;
    i = l;

    if (i >= N + 1) done = true;

    return rooms;
}