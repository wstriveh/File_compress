#ifndef __HUFFMAN_TREE_HPP__
#define __HUFFMAN_TREE_HPP__

#include "Heap.hpp"
#include "Huffman.h"

template <typename T>
HuffmanTree<T>::HuffmanTree() :_root(NULL)
{}

template <typename T>
HuffmanTree<T>::HuffmanTree(const T* array, size_t size, int vailed) : _root(NULL)
{
	this->_root = _CreateHuffmanTree(array, size, vailed);
}

template <typename T>
HuffmanNode<T>* HuffmanTree<T>::_CreateHuffmanTree(const T* array, size_t size, int valid)
{
	//ѡ��С����С��
	Heap<Node*, Less> heap;
	Node* parent = NULL;

	for (size_t i = 0; i < size; ++i)//����������
	{
		if (array[i] != valid)
		{
			heap.Push(new Node(array[i]));
		}
	}
	/*����ж�������Ҫ�� Size() > 1 ��Ϊһ���ڵ㲻��Ҫ���������Ҵ��������ڵ�ſ���һ��ȡ�����ڵ�*/
	while (heap.Size() > 1)
	{
		Node* minFirst = heap.Top();
		heap.Pop();
		Node* minSecond = heap.Top();
		heap.Pop();
		parent = new Node(minFirst->_weight + minSecond->_weight);
		parent->_left = minFirst;
		parent->_right = minSecond;
		heap.Push(parent);
	}
	return parent;
}

template <typename T>
HuffmanTree<T>::~HuffmanTree()
{
	this->_Clear(this->_root);
}

template <typename T>
void HuffmanTree<T>::_Clear(Node* root)
{
	if (root)
	{
		_Clear(root->_left);
		_Clear(root->_right);
		delete root;
	}
}

template <typename T>
HuffmanNode<T>* HuffmanTree<T>::GetHuffmanNode()
{
	return this->_root;
}

#endif 
