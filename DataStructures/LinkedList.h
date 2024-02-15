//
// Author: Michael Stepzinski
// Date: 2/12/24
// Purpose: Implement a linked list data structure
//

#include <initializer_list>

template <typename T>
class Node
{
public:
    Node(const T& value)
        : m_data{ value }
    {
    }

    Node<T>* m_next{ nullptr };
    T m_data{};
};

template <typename T>
class LinkedList
{
private:
    Node<T>* m_head{ nullptr };
    int m_size{ 0 };

public:
    // Req 001 This function shall initialize an empty linked list
    LinkedList()
    {
    }

    // Req 001 This function shall initialize a copy of the passed in list
    LinkedList(const LinkedList& list)
    {
        // get pointers to the heads of each list
        Node<T>* copy_curr{ list.m_head };
        
        // if the other list has a node
        // (this chunk keeps the other list one node ahead)
        if (copy_curr != nullptr)
        {
            // copy the node of the other list
            m_head = new Node<T>{ copy_curr->m_data };
            // advance the other list by one node
            copy_curr = copy_curr->m_next;
            m_size++;
        }
        Node<T>* curr{ m_head };

        // while the other list has values
        while (copy_curr != nullptr)
        {
            // copy the curr value of the other list
            curr->m_next = new Node<T>{ copy_curr->m_data };
            // advance curr by one node
            curr = curr->m_next;
            // advance the other list by one
            copy_curr = copy_curr->m_next;
            m_size++;
        }
    }

    // Req 001 This function shall return the number of nodes in the linked list
    int GetSize()
    {
        return m_size;
    }

    // Req 001 This function shall add a node to the end of the linked list
    void AddNode(const T& data)
    {
        Node<T>* curr{ m_head };
        if (curr == nullptr)
        {
            m_head = new Node<T>{ data };
        }
        else
        {
            while (curr->m_next != nullptr)
            {
                curr = curr->m_next;
            }
            curr->m_next = new Node<T>{ data };
        }
        m_size++;
    }

    // Req 001 This function shall add a node after the selected index, putting the node between two others if necessary
    // Req 002 This function shall throw an exception if the selected index is invalid
    void AddNode(const T& data, int index)
    {
        //
        // check if index is valid
        //

        // negative values are not valid
        if (index < 0)
            throw - 1;
        // adding a value past the head is invalid if the head doesn't exist
        else if ((m_head == nullptr) && (index != 0))
            throw - 1;
        // adding a value past the size is invalid
        else if (index >= (m_size))
            throw - 1;

        // advance curr to the desired index
        Node<T>* curr{ m_head };
        for (std::size_t i{ 0 }; i < index; ++i)
        {
            curr = curr->m_next;
        }

        Node<T>* new_node{ new Node<T>{data} };
        new_node->m_next = curr->m_next;

        curr->m_next = new_node;

        m_size++;
    }

    // Req 001 This function shall add a node to the front of the linked list
    void AddNodeToFront(const T& data)
    {
        Node<T>* new_node{ new Node<T>{data} };
        new_node->m_next = m_head;
        m_head = new_node;
        m_size++;
    }

    // Req 001 This function shall remove a node from the front of the linked list and return its value
    // Req 002 This function shall throw an exception if the list is empty
    T RemoveNodeFromFront()
    {
        if (m_size == 0)
            throw - 1;
        Node<T>* node_to_delete{ m_head };
        m_head = m_head->m_next;
        T value_to_return{ node_to_delete->m_data };
        delete node_to_delete;
        node_to_delete = nullptr;
        m_size--;
        return value_to_return;
    }

    // Req 001 This function shall remove a node from the end of the linked list
    // Req 002 This function shall throw an exception when the linked list has no values
    T RemoveNode()
    {
        // if the head is null, throw exception
        if (m_head == nullptr)
            throw - 1;

        T return_value{};
        // if the last node is also the head, just deallocate the head
        if (m_head->m_next == nullptr)
        {
            return_value = m_head->m_data;
            delete m_head;
            m_head = nullptr;
            m_size--;
            return return_value;
        }
        
        // advance curr to the second to last valid index
        Node<T>* curr{ m_head };
        while (curr->m_next->m_next != nullptr)
        {
            curr = curr->m_next;
        }

        return_value = curr->m_next->m_data;
        delete curr->m_next;
        curr->m_next = nullptr;
        
        m_size--;
        return return_value;
    }

    // Req 001 This function shall remove a node after the desired index
    // Req 002 This function shall throw an exception when the index is invalid
    T RemoveNode(int index)
    {
        // if the head is null, throw exception
        if (m_head == nullptr)
            throw - 1;
        // if the index is out of bounds ,throw exception
        if (index < 0)
            throw - 1;
        if (index >= m_size)
            throw - 1;

        // if there are only two nodes, remove the second node
        Node<T>* curr{ m_head };
        if (curr->m_next->m_next == nullptr)
        {
            // delete the node
            T return_value{ curr->m_next->m_data };
            delete curr->m_next;
            curr->m_next = nullptr;
            m_size--;
            return return_value;
        }

        // advance curr to the node before the one to be deleted
        for (std::size_t i{ 0 }; i < index - 1; ++i)
        {
            curr = curr->m_next;
        }

        // get reference to node to be deleted
        Node<T>* node_to_be_deleted{ curr->m_next };

        // point before node to after node
        curr->m_next = node_to_be_deleted->m_next;

        // delete the node
        T return_value{ node_to_be_deleted->m_data };
        delete node_to_be_deleted;
        m_size--;
        return return_value;
    }

    // Req 001 This function shall return the data at the given index if the index is valid
    // Req 002 This function shall throw an exception if the index is not valid
    T operator[](int index)
    {
        if ((index > (m_size - 1)) || (index < 0))
            throw - 1;

        Node<T>* curr{ m_head };
        for (std::size_t i{ 0 }; i < index; ++i)
        {
            curr = curr->m_next;
        }

        return curr->m_data;
    }
};