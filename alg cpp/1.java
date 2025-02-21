// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { 
        this.val = val; 
    }
    ListNode(int val, ListNode next) { 
        this.val = val; 
        this.next = next; 
    }
}

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
        // Traverse the list until we reach the end
        while (current != null && current.next != null) {
            // If the current value is the same as the next one, skip the duplicate
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                // Otherwise, move to the next node
                current = current.next;
            }
        }
        return head;
    }
}
