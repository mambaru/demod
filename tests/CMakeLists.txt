
add_test(
  NAME hash0.conf
  COMMAND demod --check-config=examples/hash/hash0.conf
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_test(
  NAME hash1.conf
  COMMAND demod --check-config=examples/hash/hash1.conf
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_test(
  NAME hash2.conf
  COMMAND demod --check-config=examples/hash/hash2.conf
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
