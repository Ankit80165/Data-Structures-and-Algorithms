#include<bits/stdc++.h>
using namespace std;


class TreeNode {
public:
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
TreeNode *takeInputLevelWise() {
	int rootData;
	cin >> rootData;
	if (rootData == 0) {
		return NULL;
	}
	TreeNode *root = new TreeNode(rootData);
	queue<TreeNode*> q;
	q.push(root);

	while (q.size() > 0) {
		TreeNode * f = q.front();
		q.pop();

		int leftData, rightData;
		cin >> leftData >> rightData;
		if (leftData != 0) {
			TreeNode* leftChild = new TreeNode(leftData);
			f->left = leftChild;
			q.push(leftChild);
		}
		if (rightData != 0) {
			TreeNode *rightChild = new TreeNode(rightData);
			f->right = rightChild;
			q.push(rightChild);
		}
	}

	return root;
}
void levelOrderTraversal(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	while (q.size() > 0) {
		TreeNode *f = q.front();
		q.pop();

		cout << f->data << " ";
		if (f->left != NULL) {
			q.push(f->left);
		}
		if (f->right != NULL) {
			q.push(f->right);
		}
	}
	cout << endl;
}
vector<int> reverseLevelOrder(TreeNode *root) {
	if (root == NULL) {
		return {};
	}
	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);
	while (q.size() > 0) {
		TreeNode *f = q.front();
		q.pop();

		res.push_back(f->data);
		if (f->right != NULL) {
			q.push(f->right);
		}
		if (f->left != NULL) {
			q.push(f->left);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
int heightOfTree(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight = heightOfTree(root->left);
	int rightHeight = heightOfTree(root->right);

	return 1 + max(leftHeight, rightHeight);
}
// diameter of the tree
pair<int, int> diameterOfTreeHelper(TreeNode *root) {
	// diameter, height
	if (root == NULL) {
		return {0, 0};
	}
	pair<int, int> leftAns = diameterOfTreeHelper(root->left);
	pair<int, int> rightAns = diameterOfTreeHelper(root->right);

	pair<int, int> ans;
	ans.first = max(1 + leftAns.second + rightAns.second, max(leftAns.first, rightAns.first));
	ans.second = 1 + max(leftAns.first, rightAns.second);
	return ans;
}
int diameterOfTree(TreeNode *root) {
	return diameterOfTreeHelper(root).first;
}
// mirror image of tree
TreeNode *mirrorOfTree(TreeNode *root) {
	if (root == NULL) {
		return root;
	}
	TreeNode *leftSubtree = mirrorOfTree(root->left);
	TreeNode *rightSubtree = mirrorOfTree(root->right);

	root->left = rightSubtree;
	root->right = leftSubtree;

	return root;
}
// iterative inorder
vector<int> inorder(TreeNode *root) {
	if (root == NULL) {
		return {};
	}
	vector<int> inorder;
	stack<TreeNode*> st;
	while (root != NULL) {
		st.push(root);
		root = root->left;
	}
	while (st.size() > 0) {
		TreeNode *t = st.top();
		st.pop();
		inorder.push_back(t->data);
		TreeNode *right = t->right;
		while (right != NULL) {
			st.push(right);
			right = right->left;
		}
	}
	return inorder;
}
// iterative preorder
vector<int> preorder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<int> preorder;
	stack<TreeNode*> st;


	while (root != NULL) {
		preorder.push_back(root->data);
		st.push(root);
		root = root->left;
	}

	while (st.size() > 0) {
		TreeNode *t = st.top();
		st.pop();
		TreeNode *right = t->right;
		while (right != NULL) {
			preorder.push_back(right->data);
			st.push(right);
			right = right->left;
		}
	}
	return preorder;
}
// postorder
vector<int> postorder(TreeNode *root) {
	if (root == NULL) {
		return {};
	}
	stack<TreeNode*> in;
	in.push(root);

	stack<int> out;
	while (in.size() > 0) {
		TreeNode *t = in.top();
		in.pop();

		out.push(t->data);
		if (t->left) {
			in.push(t->left);
		}
		if (t->right) {
			in.push(t->right);
		}
	}
	vector<int> post;
	while (out.size() > 0) {
		post.push_back(out.top());
		out.pop();
	}
	return post;
}
vector<int> diagonalTraversal(TreeNode *root) {
	vector<int> result;
	if (root == NULL) {
		return {};
	}
	queue<TreeNode*> q;
	while (root != NULL) {
		q.push(root);
		root = root->right;
	}
	while (q.size() > 0) {
		TreeNode *f = q.front();
		q.pop();
		result.push_back(f->data);

		TreeNode *leftChild = f->left;
		while (leftChild != NULL) {
			q.push(leftChild);
			leftChild = leftChild->right;
		}
	}

	return result;

}
int findIndex(string s, int start, int end) {
	if (start < end) {
		int leftBracketCount = 1;
		for (int i = start + 1; i <= end; i++) {
			if (s[i] == '(') {
				leftBracketCount++;
			} else if (s[i] == ')') {
				leftBracketCount--;
				if (leftBracketCount == 0) {
					return i;
				}
			}
		}

		return -1;
	} else {
		return -1;
	}
}
TreeNode *stringToTree(string s, int start, int end) {
	if (start <= end) {
		int nodeVal = s[start] - '0';
		TreeNode *root = new TreeNode(nodeVal);
		int index = findIndex(s, start + 1, end);
		if (index != -1) {
			root->left = stringToTree(s, start + 2, index - 1);
			root->right = stringToTree(s, index + 2, end - 1);
		}
		return root;
	} else {
		return NULL;
	}
}
printVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
string duplicateSubtree(TreeNode *root, map<string, int> &mp) {
	if (root == NULL) {
		return "";
	}
	string leftString = duplicateSubtree(root->left, mp);
	string rightString = duplicateSubtree(root->right, mp);
	string final = leftString;
	final.push_back(root->data + '0');
	final += rightString;
	mp[final]++;
	return final;
}
void allPathsSumK(TreeNode *root, int k, vector<int> &path) {

	if (root == NULL) {
		return;
	}
	path.push_back(root->data);
	allPathsSumK(root->left, k, path);
	allPathsSumK(root->right, k, path);
	int sum = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		sum += path[j];
		if (sum == k) {
			for (int k = j; k < path.size(); k++) {
				cout << path[k] << " ";
			}
			cout << endl;
		}
	}
	path.pop_back();
	return;
}
pair<int, TreeNode*> kthAncestor(TreeNode* root, int val, int k) {
	if (root == NULL) {
		return { -1, NULL};
	}
	if (root->data == val) {
		return {0, root};
	}
	pair<int, TreeNode*> o1 = kthAncestor(root->left, val, k);
	pair<int, TreeNode*> o2 = kthAncestor(root->right, val, k);
	if (o1.second == NULL && o2.second == NULL) {
		return { -1, NULL};
	}
	if (o1.second != NULL && o2.second == NULL) {
		if (o1.first + 1 <= k) {
			return {o1.first + 1, root};
		}
		if (o1.first + 1 > k) {
			return o1;
		}
	}
	if (o1.second == NULL && o2.second != NULL) {
		if (o2.first + 1 <= k) {
			return {o2.first + 1, root};
		}
		if (o2.first + 1 > k) {
			return o2;
		}
	}
}
void printLefts(TreeNode *root, int val) {
	if (root == NULL) {
		return;
	}
	printLefts(root->left, -1);
	printLefts(root->right, 1);

	if (val == -1) {
		cout << root->data << " ";
	}
	return;
}
TreeNode *bstFromPreorder(int *pre, int n, int &currIndex, int minVal, int maxVal) {
	if (currIndex >= n) {
		return NULL;
	}
	int val = pre[currIndex];
	if (val >= minVal && val <= maxVal) {
		TreeNode *root = new TreeNode(val);
		currIndex++;
		root->left = bstFromPreorder(pre, n, currIndex, minVal, root->data);
		root->right = bstFromPreorder(pre, n, currIndex, root->data, maxVal);
		return root;
	}
	else {
		return NULL;
	}
}
void binaryTreeToBST(TreeNode *root,
                     vector<int> inorder,
                     int &inStart)
{
	if (root == NULL) {
		return;
	}
	binaryTreeToBST(root->left, inorder, inStart);
	root->data = inorder[inStart];
	inStart++;
	binaryTreeToBST(root->right, inorder, inStart);
	return;
}
void inorderModified(TreeNode *root, vector<int> &inorder)
{
	if (root == NULL) {
		return;
	}
	inorderModified(root->left, inorder);
	inorder.push_back(root->data);
	inorderModified(root->right, inorder);
	return;
}
void findMedianOfBst(TreeNode *root, int &firstOption, int &secondOption) {
	if (root == NULL) {
		return;
	}

}
int medianOfBST(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int firstOption = 0;
	int secondOption = 0;
	int total = 0;
	findMedianOfBst(root, firstOption, secondOption);
	if (total % 2 == 0) {
		return (firstOption + secondOption) / 2;
	} else {
		return firstOption;
	}
}
int main() {
	TreeNode *root = takeInputLevelWise();
	levelOrderTraversal(root);

	vector<int>inorderVector;
	map<TreeNode*, pair<int, int>> mp;

	inorderModified(root, inorderVector);
	sort(inorderVector.begin(), inorderVector.end());
	int start = 0;
	binaryTreeToBST(root, inorderVector, start);
	vector<int> res = inorder(root);
	printVector(res);


	cout << endl;
}