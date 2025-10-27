#pragma once
#include <stddef.h>

extern "C"{
typedef struct objc_class* Class;
typedef struct objc_object* id;
typedef struct objc_selector* SEL;
typedef struct objc_object Protocol;

struct objc_super{
    id reciever;
    Class super_class;
};

typedef id (*IMP)(id, SEL, ...);

extern Class        objc_getClass           (const char*);
extern const char*  class_getName           (Class);
extern id           objc_msgSend            (id, SEL, ...);
extern double       objc_msgSend_fpret      (id, SEL, ...);
extern void         objc_msgSend_stret      (void*, id, SEL, ...);
extern SEL          sel_registerName        (const char*);
extern SEL          sel_getUid              (const char*);
extern const char*  sel_getName             (SEL);
extern Class        object_getClass         (id);
extern Class        objc_lookUpClass        (const char*);
extern bool         class_addMethod         (Class, SEL, IMP, const char*);
extern Class        objc_allocateClassPair  (Class, const char*, size_t);
extern Protocol*    objc_getProtocol        (const char*);
extern void         objc_registerClassPair  (Class);
extern bool         class_addProtocol       (Class, Protocol*);
}
