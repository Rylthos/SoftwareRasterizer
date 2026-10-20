#include "test.h"

#include "string.h"

#include "array.h"
#include "framebuffer.h"
#include "math.h"

void register_test(const char *name, test_func_t func) {
  if (test_count < MAX_TESTS) {
    test_registry[test_count++] = (TestCase){name, func};
  }
}

void print_test_messages(const char *test_name, TestResult result) {
  printf("[RUN] %s... ", test_name);
  switch (result) {
  case TEST_SUCCESS:
    printf("Success\n");
    break;
  case TEST_FAILURE:
    printf("Failure\n");
    break;
  }
  fprintf(stderr, "%*s", test_message_index, test_messages);
}

void add_test_message(const char *msg) {
  strncpy(test_messages + test_message_index, msg,
          MAX_FAILURE_MSG_LEN - test_message_index);
}

int main(void) {
  printf("Running %d tests ...\n", test_count);

  for (int i = 0; i < test_count; i++) {
    test_registry[i].func(test_registry[i].name);
  }

  return 0;
}
