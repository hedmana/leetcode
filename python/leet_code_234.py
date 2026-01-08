from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        temp = head
        stack = []
        is_palin = True

        while temp != None:
            stack.append(temp.val)
            temp = temp.next

        while head != None:
            i = stack.pop()

            if head.val == i:
                is_palin = True
            else:
                is_palin = False
                break

            head = head.next

        return is_palin


def main():
    test1 = ListNode(1, ListNode(2, ListNode(2)))

    sol = Solution()

    ans = sol.isPalindrome(test1)

    print("Final answer:", ans)


main()
