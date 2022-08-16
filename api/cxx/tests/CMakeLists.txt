
set(CHAIR_TESTS_LIST
    "smoke_test.cxx"
    "main.cxx"
)

set(CHAIR_TESTS_LINKS
    chair
)
include(utils_add_tests)
add_tests(chair_tests "${CHAIR_TESTS_LIST}" "${CHAIR_TESTS_LINKS}")