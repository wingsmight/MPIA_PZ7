#include "catch.hpp"

#include "activities.h"

#include <set>

// Convert activities to set of vectors for equality comparison and pretty printing.
std::set<std::vector<int>> to_set(const std::vector<Activity> &acts) {
    std::set<std::vector<int>> s;
    for (const auto &a: acts) {
        s.insert(std::vector<int>({a.start, a.finish}));
    }
    return s; 
}

TEST_CASE( "Empty", "[activity]" ) {
     CHECK( to_set(get_max_activities({})) == to_set({}) );
}

TEST_CASE( "One activity", "[activity]" ) {
    CHECK( to_set(get_max_activities({ {2, 3} })) == to_set({ {2, 3} }) );
}

TEST_CASE( "Two compatibles", "[activity]" ) {
    CHECK( to_set(get_max_activities({ {3, 4}, {2, 3} })) == to_set({ {2, 3}, {3, 4} }) );
}

TEST_CASE( "Two overlaps", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 5}, {3, 4} }));
    CHECK( (answer == to_set({ {2, 5} }) || answer == to_set({ {3, 4} })) );
}

TEST_CASE( "Two incompatibles", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {3, 6}, {2, 5} }));
    CHECK( (answer == to_set({ {2, 5} }) || answer == to_set({ {3, 6} })) );
}

TEST_CASE( "Three activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {5, 8} }));
    CHECK( answer == to_set({ {1, 4}, {5, 8} }) );
}

TEST_CASE( "Four activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {7, 10}, {5, 8} }));
    CHECK( (answer == to_set({ {1, 4}, {5, 8} }) || answer == to_set({ {2, 6}, {7, 10} })) );
}

TEST_CASE( "Five activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {7, 10}, {5, 8}, {9, 12} }));
    CHECK( answer == to_set({ {1, 4}, {5, 8}, {9, 12} }) );
}

TEST_CASE( "Big one", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {3, 5}, {1, 4}, {5, 7}, {0, 6},
                                                    {3, 9}, {5, 9}, {8, 11}, {6, 10},
                                                    {8, 12}, {2, 14}, {12, 16} }));
    CHECK( (answer == to_set({ {1, 4}, {5, 7}, {8, 11}, {12, 16} }) ||
              answer == to_set({ {3, 5}, {5, 7}, {8, 12}, {12, 16}})) );
}
