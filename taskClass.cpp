#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

//fictitious class for a todo app that manages the task entity itself
//made to demo testing capabilities

class Task {
public:
  Task(const std::string& name)
  {
    if (name.empty()) {
      throw std::invalid_argument("Task name cannot be empty"); 
    }
    else {
      taskName = name;
    }
    isCompleted = false;
  }

  void markCompleted()
  {
    isCompleted = true;
  }

  bool checkTaskCompletion()
  {
    return isCompleted;
  }
 
  std::string getName()
  {
    return taskName;
  }

private:
  std::string taskName;
  bool isCompleted = false;
};

//tests using gtest
TEST(TaskTest, ConstructorStoresName)
{
  Task test("Make Dinner");
  EXPECT_EQ(test.getName(), "Make Dinner");
  EXPECT_FALSE(test.checkTaskCompletion());
}

TEST(TaskTest, DoesNotAcceptEmptyName)
{
  EXPECT_THROW(Task(""), std::invalid_argument);
}

TEST(TaskTest, MarkCompleted)
{
  Task test("Make Lunch");
  test.markCompleted();
  EXPECT_TRUE(test.checkTaskCompletion());
}

TEST(TaskTest, TasksDefaultToNotCompleted)
{
  Task test("Make Lunch");
  EXPECT_FALSE(test.checkTaskCompletion());
}


