#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 10

int n;
int dist[MAX][MAX];
char cities[MAX][50];

int memo[1 << MAX][MAX];
int parent[1 << MAX][MAX];

// -----------------------------
// GREEDY APPROACH
// -----------------------------
void greedy_tsp() {
    int visited[MAX] = {0};
    int route[MAX + 1];
    int total_cost = 0;

    int current = 0;
    route[0] = current;
    visited[current] = 1;

    for (int i = 1; i < n; i++) {
        int next_city = -1;
        int min_dist = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < min_dist) {
                min_dist = dist[current][j];
                next_city = j;
            }
        }

        route[i] = next_city;
        visited[next_city] = 1;
        total_cost += min_dist;
        current = next_city;
    }

    total_cost += dist[current][0];
    route[n] = 0;

    printf("\n===== GREEDY ROUTE =====\n");
    for (int i = 0; i <= n; i++) {
        printf("%s", cities[route[i]]);
        if (i < n) printf(" -> ");
    }
    printf("\nTotal Cost: %d\n", total_cost);
}

// -----------------------------
// DP FUNCTION
// -----------------------------
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (memo[mask][pos] != -1)
        return memo[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);

            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }

    return memo[mask][pos] = ans;
}

// -----------------------------
// PRINT DP PATH
// -----------------------------
void print_dp_path() {
    int mask = 1;
    int pos = 0;

    printf("\n===== OPTIMAL ROUTE (DP) =====\n");
    printf("%s", cities[0]);

    while (mask != (1 << n) - 1) {
        int next = parent[mask][pos];
        printf(" -> %s", cities[next]);

        mask |= (1 << next);
        pos = next;
    }

    printf(" -> %s", cities[0]);
}

// -----------------------------
// INPUT SECTION
// -----------------------------
void input_data() {
    printf("Enter number of cities (Max 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter city %d name: ", i);
        scanf("%s", cities[i]);
    }

    printf("\nEnter Distance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distance from %s to %s: ", cities[i], cities[j]);
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
            parent[i][j] = -1;
        }
    }
}

// -----------------------------
// GUI MENU SIMULATION
// -----------------------------
void menu() {
    int choice;
    do {
        printf("\n\n===== SMART ROUTE OPTIMIZER MENU =====\n");
        printf("1. Enter City Data\n");
        printf("2. Show Greedy Route\n");
        printf("3. Show Optimal Route (DP)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_data();
                break;

            case 2:
                greedy_tsp();
                break;

            case 3: {
                int optimal_cost = tsp(1, 0);
                print_dp_path();
                printf("\nOptimal Cost: %d\n", optimal_cost);
                break;
            }

            case 4:
                printf("Exiting Smart Route Optimizer...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);
}

// -----------------------------
// MAIN
// -----------------------------
int main() {
    printf("=====================================\n");
    printf("      SMART ROUTE OPTIMIZER GUI      \n");
    printf("=====================================\n");

    menu();

    return 0;
}