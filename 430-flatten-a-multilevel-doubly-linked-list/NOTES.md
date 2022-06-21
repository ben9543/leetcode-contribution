# Edge cases:

- When the end of child linkedlist is the last node. In this case, the next node of parent is null and the child cannot point to the proper node
```
()->()
    |
    ()->()->()
            end
```
