#include <gtest/gtest.h>

#include <cmath>
#include <functional>

#include "../../s21_containers.h"

class RBTreeTest : public ::testing::Test {
 protected:
  class TestTree : public s21::RBTree<int, char> {
   public:
    using s21::RBTree<int, char>::RBTree;
    using s21::RBTree<int, char>::findNode;
    using s21::RBTree<int, char>::fixDoubleBlack;
    using s21::RBTree<int, char>::rightRotate;
    using s21::RBTree<int, char>::GetRoot;
    using s21::RBTree<int, char>::GetMin;
    using s21::RBTree<int, char>::RecursiveDelete;
  };

  TestTree my_tree;
};

// Тест для метода GetRoot
TEST_F(RBTreeTest, GetRoot) {
  EXPECT_EQ(my_tree.GetRoot(), nullptr);
  my_tree.insert(1, 'a');
  EXPECT_NE(my_tree.GetRoot(), nullptr);
}

// Тест для метода leftRotate
TEST_F(RBTreeTest, LeftRotate) {
  my_tree.insert(1, 'a');
  my_tree.insert(2, 'b');
  my_tree.insert(3, 'c');

  auto* root = my_tree.GetRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->key, 2);
  EXPECT_EQ(root->color, s21::BLACK);
  EXPECT_EQ(root->left->key, 1);
  EXPECT_EQ(root->right->key, 3);
}

// Тест для метода rightRotate
TEST_F(RBTreeTest, RightRotate) {
  my_tree.insert(3, 'c');
  my_tree.insert(2, 'b');
  my_tree.insert(1, 'a');

  auto* root = my_tree.GetRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->key, 2);
  EXPECT_EQ(root->color, s21::BLACK);
  EXPECT_EQ(root->left->key, 1);
  EXPECT_EQ(root->right->key, 3);
}

// Тест для метода insert
TEST_F(RBTreeTest, Insert) {
  my_tree.insert(1, 'a');
  EXPECT_TRUE(my_tree.contains(1));
}

// Тест для метода remove
TEST_F(RBTreeTest, Remove) {
  my_tree.insert(1, 'a');
  my_tree.remove(1);
  EXPECT_FALSE(my_tree.contains(1));
}

// Тест для метода findNode
TEST_F(RBTreeTest, FindNode) {
  my_tree.insert(1, 'a');
  EXPECT_TRUE(my_tree.contains(1));
  EXPECT_FALSE(my_tree.contains(2));
}

// Тест для метода GetMin
TEST_F(RBTreeTest, GetMin) {
  my_tree.insert(2, 'b');
  my_tree.insert(1, 'a');
  EXPECT_EQ(my_tree.GetMin(my_tree.GetRoot())->key, 1);
}

// Тест для метода RecursiveDelete
TEST_F(RBTreeTest, RecursiveDelete) {
  my_tree.insert(1, 'a');
  my_tree.remove(1);
  EXPECT_FALSE(my_tree.contains(1));
  EXPECT_EQ(my_tree.size(), 0);
}

// Расширенный тест для insert с различными случаями
TEST_F(RBTreeTest, InsertComplexCase) {
  my_tree.insert(10, 'a');
  my_tree.insert(20, 'b');
  my_tree.insert(30, 'c');
  my_tree.insert(15, 'd');
  my_tree.insert(25, 'e');

  auto* root = my_tree.GetRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->key, 20);
  EXPECT_EQ(root->left->right->key, 15);
  EXPECT_EQ(root->right->left->key, 25);
}

// Тест для удаления узла с двумя потомками
TEST_F(RBTreeTest, RemoveNodeWithTwoChildren) {
  my_tree.insert(50, 'a');
  my_tree.insert(30, 'b');
  my_tree.insert(70, 'c');
  my_tree.insert(20, 'd');
  my_tree.insert(40, 'e');

  my_tree.remove(30);
  EXPECT_FALSE(my_tree.contains(30));
  EXPECT_EQ(my_tree.size(), 4);
}

// Тест для удаления левого поддерева
TEST_F(RBTreeTest, RecursiveDeleteLeftSubtree) {
  my_tree.insert(5, 'a');
  my_tree.insert(3, 'b');
  my_tree.insert(7, 'c');

  my_tree.RecursiveDelete(my_tree.GetRoot(), 3);
  EXPECT_FALSE(my_tree.contains(3));
  EXPECT_EQ(my_tree.size(), 2);
}

// Тест для удаления узла с красным братом
TEST_F(RBTreeTest, RemoveWithRedSibling) {
  my_tree.insert(20, 'a');
  my_tree.insert(10, 'b');
  my_tree.insert(30, 'c');
  my_tree.insert(5, 'd');
  my_tree.insert(15, 'e');

  my_tree.remove(5);
  EXPECT_FALSE(my_tree.contains(5));
  EXPECT_TRUE(my_tree.contains(10));
  EXPECT_TRUE(my_tree.contains(15));
}

// Тест для удаления правого поддерева
TEST_F(RBTreeTest, RemoveWithRightSubtree) {
  my_tree.insert(20, 'a');
  my_tree.insert(10, 'b');
  my_tree.insert(30, 'c');
  my_tree.insert(25, 'd');
  my_tree.insert(35, 'e');

  my_tree.remove(30);
  EXPECT_FALSE(my_tree.contains(30));
  EXPECT_TRUE(my_tree.contains(35));
  EXPECT_TRUE(my_tree.contains(25));
}

// Тест для удаления узла с двумя потомками
TEST_F(RBTreeTest, ComplexRemoveBalancing) {
  my_tree.insert(20, 'a');
  my_tree.insert(10, 'b');
  my_tree.insert(30, 'c');
  my_tree.insert(5, 'd');
  my_tree.insert(15, 'e');
  my_tree.insert(25, 'f');
  my_tree.insert(35, 'g');

  my_tree.remove(5);
  my_tree.remove(35);
  EXPECT_FALSE(my_tree.contains(5));
  EXPECT_FALSE(my_tree.contains(35));
  EXPECT_TRUE(my_tree.contains(10));
  EXPECT_TRUE(my_tree.contains(30));
}

// Тест для правого вращения с родителем
TEST_F(RBTreeTest, RightRotateWithParent) {
  my_tree.insert(30, 'a');
  my_tree.insert(20, 'b');
  my_tree.insert(40, 'c');
  my_tree.insert(10, 'd');

  auto* node = my_tree.findNode(20);
  ASSERT_NE(node, nullptr);
  my_tree.rightRotate(node);

  // Проверяем новую структуру дерева
  EXPECT_EQ(my_tree.GetRoot()->key, 30);
  EXPECT_EQ(my_tree.GetRoot()->left->key, 10);
  EXPECT_EQ(my_tree.GetRoot()->left->right->key, 20);
  EXPECT_EQ(my_tree.GetRoot()->right->key, 40);

  // Проверяем родительские связи
  EXPECT_EQ(node->parent->key, 10);
  EXPECT_EQ(my_tree.GetRoot()->left->parent->key, 30);
}

// Тест для случая красного дяди в левой ветви
TEST_F(RBTreeTest, InsertFixupRedUncleLeft) {
  my_tree.insert(10, 'a');
  my_tree.insert(5, 'b');
  my_tree.insert(15, 'c');
  my_tree.insert(3, 'd');

  auto* node = my_tree.findNode(3);
  ASSERT_NE(node, nullptr);
  EXPECT_EQ(node->color, s21::RED);
  EXPECT_EQ(my_tree.GetRoot()->color, s21::BLACK);
}

// Тест для двойного черного узла с красным sibling
TEST_F(RBTreeTest, FixDoubleBlackWithRedSibling) {
  my_tree.insert(50, 'a');
  my_tree.insert(30, 'b');
  my_tree.insert(70, 'c');
  my_tree.insert(20, 'd');

  my_tree.remove(20);

  EXPECT_FALSE(my_tree.contains(20));
  EXPECT_EQ(my_tree.GetRoot()->color, s21::BLACK);
  EXPECT_EQ(my_tree.GetRoot()->left->color, s21::BLACK);
}

// Тест для случая удаления корневого узла
TEST_F(RBTreeTest, RemoveRootNode) {
  my_tree.insert(100, 'a');
  my_tree.remove(100);

  EXPECT_EQ(my_tree.GetRoot(), nullptr);
  EXPECT_TRUE(my_tree.empty());
}

// Тест для конструктора initializer_list
TEST_F(RBTreeTest, InitializerListConstructor) {
  TestTree test_tree{{10, 'a'}, {20, 'b'}, {30, 'c'}};

  EXPECT_EQ(test_tree.size(), 3);
  EXPECT_TRUE(test_tree.contains(10));
  EXPECT_TRUE(test_tree.contains(20));
  EXPECT_TRUE(test_tree.contains(30));

  auto* root = test_tree.GetRoot();
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->key, 20);
  EXPECT_EQ(root->color, s21::BLACK);
}

// Дополнительный тест для пустого списка
TEST_F(RBTreeTest, EmptyInitializerList) {
  TestTree test_tree{};
  EXPECT_TRUE(test_tree.empty());
}

// Тест для копирования через initializer_list
TEST_F(RBTreeTest, CopyInitializerListTree) {
  TestTree original{{5, 'a'}, {3, 'b'}, {7, 'c'}};
  TestTree copy(original);

  EXPECT_EQ(copy.size(), 3);
  EXPECT_TRUE(copy.contains(5));
  EXPECT_TRUE(copy.contains(3));
  EXPECT_TRUE(copy.contains(7));
}

// Тест для перемещающего присваивания с непустым деревом
TEST_F(RBTreeTest, MoveAssignmentWithData) {
  my_tree.insert(10, 'a');
  my_tree.insert(20, 'b');

  TestTree other;
  other = std::move(my_tree);

  EXPECT_EQ(my_tree.size(), 0);
  EXPECT_EQ(other.size(), 2);
}

// Тест для cbegin() с пустым деревом
TEST_F(RBTreeTest, CbeginOnEmptyTree) {
  auto it = my_tree.cbegin();
  EXPECT_EQ(it, my_tree.cend());
}

// Тест для перемещающего конструктора
TEST_F(RBTreeTest, MoveConstructor) {
  my_tree.insert(5, 'a');
  my_tree.insert(3, 'b');

  TestTree moved(std::move(my_tree));
  EXPECT_EQ(moved.size(), 2);
  EXPECT_EQ(my_tree.size(), 0);
}

// Тест для итерации через cbegin/cend
TEST_F(RBTreeTest, ConstIteratorTraversal) {
  my_tree.insert(3, 'c');
  my_tree.insert(1, 'a');
  my_tree.insert(2, 'b');

  auto it = my_tree.cbegin();
  EXPECT_EQ((*it).first, 1);
  ++it;
  EXPECT_EQ((*it).first, 2);
  ++it;
  EXPECT_EQ((*it).first, 3);
  ++it;
  EXPECT_EQ(it, my_tree.cend());
}

// Тест для копирования пустого дерева
TEST_F(RBTreeTest, CopyEmptyTree) {
  TestTree emptyTree;
  TestTree copy(emptyTree);
  EXPECT_TRUE(copy.empty());
  EXPECT_EQ(copy.size(), 0);
}

// Тест для перемещающего присваивания с пустым деревом
TEST_F(RBTreeTest, MoveAssignmentEmptyTree) {
  TestTree empty;
  TestTree other;
  other = std::move(empty);
  EXPECT_TRUE(other.empty());
  EXPECT_EQ(empty.size(), 0);
}

// Тест для константной версии find
TEST_F(RBTreeTest, ConstFind) {
  my_tree.insert(5, 'a');
  const TestTree& const_tree = my_tree;
  auto it = const_tree.find(5);
  EXPECT_NE(it, const_tree.cend());
  EXPECT_EQ((*it).first, 5);
}

// Тест для метода max_size
TEST_F(RBTreeTest, MaxSize) { EXPECT_GT(my_tree.max_size(), 0); }

// Тест для функционала swap
TEST_F(RBTreeTest, SwapTrees) {
  TestTree tree1;
  tree1.insert(1, 'a');
  TestTree tree2;
  tree2.insert(2, 'b');

  tree1.swap(tree2);

  EXPECT_TRUE(tree1.contains(2));
  EXPECT_TRUE(tree2.contains(1));
  EXPECT_EQ(tree1.size(), 1);
  EXPECT_EQ(tree2.size(), 1);
}

// Тест для функционала merge
TEST_F(RBTreeTest, MergeTrees) {
  TestTree source;
  source.insert(10, 'a');
  source.insert(20, 'b');

  my_tree.insert(5, 'c');
  my_tree.merge(source);

  EXPECT_TRUE(my_tree.contains(5));
  EXPECT_TRUE(my_tree.contains(10));
  EXPECT_TRUE(my_tree.contains(20));
  EXPECT_TRUE(source.empty());
}

// Тест для присваивания пустого дерева
TEST_F(RBTreeTest, AssignEmptyTree) {
  TestTree empty;
  my_tree.insert(1, 'a');
  my_tree = empty;
  EXPECT_TRUE(my_tree.empty());
  EXPECT_EQ(my_tree.size(), 0);
}

// Тест для проверки баланса после последовательной вставки
TEST_F(RBTreeTest, BalanceAfterSequentialInsert) {
  for (int i = 1; i <= 100; ++i) {
    my_tree.insert(i, 'a' + (i % 26));
  }

  std::function<int(typename s21::RBTree<int, char>::RBTreeNode*)> getHeight =
      [&getHeight](typename s21::RBTree<int, char>::RBTreeNode* node) -> int {
    if (!node) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
  };

  int height = getHeight(my_tree.GetRoot());
  EXPECT_LE(height, 2 * std::log2(my_tree.size() + 1));
}

// Тест для проверки свойств красно-черного дерева
TEST_F(RBTreeTest, RedBlackProperties) {
  for (int i = 1; i <= 100; ++i) {
    my_tree.insert(i, 'a' + (i % 26));
  }

  std::function<bool(typename s21::RBTree<int, char>::RBTreeNode*)>
      checkRedBlackProperties =
          [&checkRedBlackProperties](
              typename s21::RBTree<int, char>::RBTreeNode* node) -> bool {
    if (!node) return true;

    if (node->color == s21::RED) {
      if (node->left && node->left->color == s21::RED) return false;
      if (node->right && node->right->color == s21::RED) return false;
    }

    return checkRedBlackProperties(node->left) &&
           checkRedBlackProperties(node->right);
  };

  EXPECT_TRUE(checkRedBlackProperties(my_tree.GetRoot()));
  EXPECT_EQ(my_tree.GetRoot()->color, s21::BLACK);
}
