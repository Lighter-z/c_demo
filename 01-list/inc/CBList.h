#ifndef INC_CBLIST_H__
#define INC_CBLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#define CB_CONTAINER_OF(ptr, type, member) \
        ((type *)((char *)(ptr) - (uinsigned long)(&((type *) 0)->member)))

#define CB_LIST_OBJECT_INIT(object) {&(object), &(object)}

#define CB_LIST_ENTRY(node, type, member) CB_CONTAINER_OF(node, type, member)

#define CB_LIST_FOR_EACH(pos, head) \
        for(pos = (head)->next_; pos != (head); pos = pos->next_)


typedef struct CBListNode CBList;

struct CBListNode {
  struct CBListNode *next_;
  struct CBListNode *priv_;
  void *data_;
};

static inline void CBListInit(CBList *l, void *data) {
  l->next_ = l->priv_ = l;
  l->data_ = data;
}

static inline void CBListInsertAfter(CBList *l, CBList *n) {
  l->next_->priv_ = n;
  n->next_ = l->next_;

  l->next_ = n;
  n->priv_ = l;
}

static inline void CBListInsertBefore(CBList *l, CBList *n) {
  l->priv_->next_ = n;
  n->priv_ = l->priv_;

  l->priv_ = n;
  n->next_ = l;
}

static inline void CBListRemove(CBList *n) {
  n->next_->priv_ = n->priv_;
  n->priv_->next_ = n->next_;

  n->next_ = n->priv_ = n;
}

static inline int CBListIsEmpty(const CBList *l) {
  return l->next_ == l;
}

static inline unsigned int CBListLen(const CBList *l) {
  unsigned int len = 0;
  const CBList *p = l;

  while(p->next_ != l) {
    p = p->next_;
    len++;
  }
  return len;
}

#ifdef __cplusplus
}
#endif

#endif /* INC_CBLIST_H__ */
