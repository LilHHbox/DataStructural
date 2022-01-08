  def _rb_delete_no_child(self, node):
        """红黑树删除两个子节点都为空的节点"""
        if node == self.root:
            self.root = None
            self.root.color = 'black'
            return
        factor_node = node
        # 如果待删除节点为黑节点则需要进行调整
        if factor_node.color is 'black':
            while True:
                parent_node = factor_node.parent
                brother_node = parent_node.right_child if factor_node is parent_node.left_child else parent_node.left_child
                # 待删除节点是左子节点
                if factor_node is parent_node.left_child:
                    # 如果兄弟节点是黑节点
                    if brother_node.color is 'black':
                        # 如果兄弟节点没有子节点(递归处理时如果兄弟节点的两个子节点都是黑节点)
                        if brother_node.left_child is None and brother_node.right_child is None or \
                        ((brother_node.left_child and brother_node.left_child.color is 'black') and
                        (brother_node.right_child and brother_node.right_child.color is 'black')):
                            self.change_color(brother_node)
                            if parent_node.color is 'red':
                                self.change_color(parent_node)
                                break
                            else:
                                if parent_node == self.root:
                                    break
                                factor_node = parent_node
                        # 如果兄弟节点有右子节点，此右节点一定是红节点(递归处理时，如果兄弟节点的右子节点为红节点)
                        elif brother_node.right_child is not None and brother_node.right_child.color is 'red':
                            brother_node.color = parent_node.color
                            parent_node.color, brother_node.right_child.color = 'black', 'black'
                            self.left_rotate(parent_node)
                            break
                        # 如果兄弟节点有左节点，此左节点一定是红节点(递归处理时，如果兄弟节点的左子节点为红节点)
                        else:
                            brother_node.color, brother_node.left_child.color = 'red', 'black'
                            self.right_rotate(brother_node)
                    # 如果兄弟节点是红节点
                    elif brother_node.color is 'red':
                        self.change_color(parent_node)
                        self.change_color(brother_node)
                        self.left_rotate(parent_node)
                # 待删除节点是右子节点
                if factor_node is parent_node.right_child:
                    if brother_node.color is 'black':
                        # 如果兄弟节点没有子节点(递归处理时如果兄弟节点的两个子节点都是黑节点)
                        if brother_node.left_child is None and brother_node.right_child is None or \
                        ((brother_node.left_child and brother_node.left_child.color is 'black') and
                        (brother_node.right_child and brother_node.right_child.color is 'black')):
                            self.change_color(brother_node)
                            if parent_node.color is 'red':
                                self.change_color(parent_node)
                                break
                            else:
                                if parent_node == self.root:
                                    break
                                factor_node = parent_node
                        # 如果兄弟节点有左节点，此左节点一定是红节点(递归处理时，如果兄弟节点的左子节点为红节点)
                        elif brother_node.left_child is not None and brother_node.left_child.color is 'red':
                            brother_node.color = parent_node.color
                            parent_node.color, brother_node.left_child.color = 'black', 'black'
                            self.right_rotate(parent_node)
                            break
                        # 如果兄弟节点有右节点，此右节点一定是红节点(递归处理时，如果兄弟节点的右子节点为红节点)
                        else:
                            brother_node.color, brother_node.right_child.color = 'red', 'black'
                            self.left_rotate(brother_node)
                    # 如果兄弟节点是红节点
                    elif brother_node.color is 'red':
                        self.change_color(parent_node)
                        self.change_color(brother_node)
                        self.right_rotate(parent_node)
        if node is node.parent.left_child:
            node.parent.left_child = None
        else:
            node.parent.right_child = None
        node.parent = None
