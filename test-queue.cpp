#include "object.h"
#include "string.h"
#include "queue.h"

// testing output functions taken from starter tests of warmup 2
void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

int main(int argc, char** argv) {
    Object* a = new Object();
    Object* b = new Object();
    Object* c = new Object(a);

    String* p = new String("hello");
    String* q = new String("world");
    String* r = new String(p);

    // Queue tests
    Queue* x = new Queue();
    Queue* y = new Queue();
    t_true(x->peek() == nullptr);
    t_true(x->dequeue() == nullptr);
    OK("empty queue tests");
    x->enqueue(p)->enqueue(q);
    Queue* z = new Queue(x);
    t_false(x->equals(y));
    t_true(x->equals(z));
    t_true(x->size() == 2);
    OK("push queue tests");
    t_true(x->dequeue()->equals(p));
    OK("pop queue tests");
    y->enqueue(q);
    x->enqueue(p);
    y->enqueue(p);
    t_true(x->equals(y));
    t_true(x->peek()->equals(q));
    z = new Queue();
    z->enqueue(a)->enqueue(b);
    t_true(z->size() == 2);
    t_true(z->dequeue()->equals(a));
    t_true(z->peek()->equals(b));
    OK("Everything passed");

    return 0;
}
