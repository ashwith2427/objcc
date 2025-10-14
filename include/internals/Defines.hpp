#pragma once
#ifndef DEFINES_H
#define DEFINES_H
extern "C"{
typedef struct objc_class* Class;
typedef struct objc_object* id;
typedef struct objc_selector* SEL;
typedef struct objc_object Protocol;

struct objc_super{
    id reciever;
    Class super_class;
};

extern Class        objc_getClass           (const char*);
extern const char*  class_getName           (Class);
extern id           objc_msgSend            (id, SEL, ...);
extern double       objc_msgSend_fpret      (id, SEL, ...);
extern void         objc_msgSend_stret      (void*, id, SEL, ...);
extern SEL          sel_registerName        (const char*);
extern Class        object_getClass         (id);
}
#endif
