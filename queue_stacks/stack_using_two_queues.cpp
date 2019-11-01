
https://www.ritambhara.in/category/algorithm/

Method-1: Push is constant time but Pop operation is O(n) time
	Push:
		push in queue1
	Pop:
		1. while queue1 is not empty
			1. pop until last-1 element
			2. push in queue2
		2. swap queue1 and queue2


Method-2: Pop is constant time but Push operation is O(n) time
	push:
		1. put data in queue2 (as queue2 is empty and it will be in front)
		2. Now empty queue1, tranfer all the data in queue2
		3. swap name of queue1 and queue2
	Pop:
		pop from top of queue1



Method-1: Push is constant time but Pop operation is O(n) time

    void SpecialStack::push(int data){
        queue1.enqueue(data)
    }
    int SpecialStack::pop(){  
        int returnValue =-1; // indicate Stack Empty.
        while(!queue1.isEmpty())
        {
            returnValue = queue1.dequeue();
            // If it was last element of queue1. return it.
            if(queue1.isEmpty())
                break;
            else
                queue2.enqueue(returnValue);
        }
        // swap the names of queue1 and queue2.
        // If swapping is not possible then we will have to move all the elements from queue2 to queue1
        // or have another flag to indicate the active queue.
        Node * temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        return returnValue;
    }

Method-2: Pop is constant time but Push operation is O(n) time
	
    void SpecialStack::push(int data){
        queue2.enqueue(data);
        while(!queue1.isEmpty()){
            queue2.enqueue(queue1.dequeue());
        }
        // swap the names of queue1 and queue2.
        // If swapping is not possible then we will have to move all the elements from queue2 to queue1
        // or have another flag to indicate the active queue.
        Node * temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }
    // Put proper check to see if no element in Queues
    int SpecialStack::pop(){  
      return queue.dequeue();
    }