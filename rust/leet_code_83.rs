pub struct Solution;

pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut cur = &mut dummy.next;

        while cur.is_some() {
            let delete_next = {
                let node = cur.as_mut().unwrap();

                match node.next.as_ref() {
                    Some(next) => next.val == node.val,
                    None => false,
                }
            };

            if delete_next {
                let node = cur.as_mut().unwrap();

                if let Some(mut next_node) = node.next.take() {
                    node.next = next_node.next.take();
                }
            } else {
                let next_link = {
                    let node = cur.as_mut().unwrap();
                    &mut node.next
                };
                cur = next_link;
            }
        }

        dummy.next
    }
}

fn main() {
    let mut head = ListNode::new(1);
    let mut node2 = ListNode::new(2);
    let node3 = ListNode::new(3);

    node2.next = Some(Box::new(node3));
    head.next = Some(Box::new(node2));

    let ans = Solution::delete_duplicates(Some(Box::new(head)))
        .unwrap()
        .val;

    println!("{ans}");
}
