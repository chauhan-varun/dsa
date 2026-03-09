public class Pre {
  public static int[] preOrder(Node root) {
    int[] arr = new int[100];
    return pre(root, arr);
  }

  public static int[] pre(Node root, int[] arr) {
    if (root == null) {
      return arr;
    }
    arr.add(root.data);
    arr = pre(root.left, arr);
    arr = pre(root.right, arr);
  }
}

class Node {
  int data;
  Node left;
  Node right;
}
