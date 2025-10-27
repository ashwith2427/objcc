#pragma once
typedef unsigned long NSUInteger;

#define _NS_ENUM(type, name) enum name : type
#define _NS_OPTIONS(type, name) \
    using name = type;          \
    enum : name

_NS_OPTIONS(NSUInteger, NSWindowStyleMask) {
    NSWindowStyleMaskBorderless = 0,
    NSWindowStyleMaskTitled = 1 << 0,
    NSWindowStyleMaskClosable = 1 << 1,
    NSWindowStyleMaskMiniaturizable = 1 << 2,
    NSWindowStyleMaskResizable    = 1 << 3,
    NSWindowStyleMaskTexturedBackground API_DEPRECATED("Textured window style should no longer be used", macos(10.2, 11.0)) = 1 << 8,
    NSWindowStyleMaskUnifiedTitleAndToolbar = 1 << 12,
    NSWindowStyleMaskFullScreen API_AVAILABLE(macos(10.7)) = 1 << 14,
    NSWindowStyleMaskFullSizeContentView API_AVAILABLE(macos(10.10)) = 1 << 15,
    NSWindowStyleMaskUtilityWindow = 1 << 4,
    NSWindowStyleMaskDocModalWindow = 1 << 6,
    NSWindowStyleMaskNonactivatingPanel = 1 << 7,
    NSWindowStyleMaskHUDWindow API_AVAILABLE(macos(10.6)) = 1 << 13
};

_NS_ENUM(NSUInteger, NSBackingStoreType) {
    NSBackingStoreRetained = 0,
    NSBackingStoreNonretained = 1,
    NSBackingStoreBuffered = 2,
};
