/***********************************************************************
 ** Etresoft, Inc.
 ** Copyright (c) 2017. All rights reserved.
 **********************************************************************/

#import "StorageDevice.h"

// Volume types.
#define kEFIVolume @"efivolume" 
#define kCoreStorageVolume @"corestoragevolume" 
#define kRAIDMemberVolume @"raidmembervolume" 
#define kRAIDSetVolume @"raidsetvolume" 
#define kFusionVolume @"fusionvolume" 
#define kAPFSContainerVolume @"apfscontainervolume" 
#define kPrebootVolume @"prebootvolume" 
#define kRecoveryVolume @"recovery" 
#define kVMVolume @"recovery" 

@interface Volume : StorageDevice
  {
  // The UUID.
  NSString * myUUID;
  
  // The filesystem.
  NSString * myFilesystem;
  
  // The mount point.
  NSString * myMountpoint;
  
  // Is the volume encrypted?
  BOOL myEncrypted;
  
  // Encryption status.
  NSString * myEncryptionStatus;
  
  // Encryption progress.
  int myEncryptionProgress;
  
  // Free space.
  NSUInteger myFreeSpace;

  // Is this a shared container?
  BOOL myShared;
  
  // Is this volume read-only?
  BOOL myReadOnly;
  
  // A volume has one or more physical drives.
  // Use device identifier only to avoid cicular references.
  NSMutableSet * myPhysicalDevices;
  }
  
// The UUID.
@property (retain, nullable) NSString * UUID;

// The filesystem.
@property (retain, nullable) NSString * filesystem;

// The mount point.
@property (retain, nullable) NSString * mountpoint;

// Is the volume encrypted?
@property (assign) BOOL encrypted;

// Encryption status.
@property (retain, nullable) NSString * encryptionStatus;

// Encryption progress.
@property (assign) int encryptionProgress;

// Free space.
@property (assign) NSUInteger freeSpace;

// Is this a shared volume?
@property (assign) BOOL shared;

// Is this volume read-only?
@property (assign) BOOL readOnly;

// A volume has one or more physical drives.
// Use device identifier only to avoid cicular references.
@property (retain, readonly, nonnull)  NSSet * physicalDevices;

// Constructor with output from diskutil info -plist.
- (nullable instancetype) initWithDiskUtilInfo: 
  (nullable NSDictionary *) plist;

// Class inspection.
- (BOOL) isVolume;

// Add a physical device reference, de-referencing any virtual devices or
// volumes.
- (void) addPhysicalDevice: (nonnull NSString *) device;

@end
