/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDMANAGERWRAP_H
#define HMDMANAGERWRAP_H

#include <node.h>

#include "HMDDevice.h"

using namespace v8;

class HMDManagerWrap : public node::ObjectWrap {
	private:
		HMDDevice* _hmdDevice;

  		// Class Methods
		HMDManagerWrap(const Arguments& args);
  		~HMDManagerWrap();

		// Required V8 Methods
		static Persistent<Function> constructor;
		static Handle<Value> New(const Arguments& args);

		// Wrapped Property Methods
  		static Handle<Value> GetDeviceInfoAsync(const Arguments& args);
		static void GetDeviceInfoRequestAsync(uv_work_t *r);
		static void GetDeviceInfoRequestAfterAsync(uv_work_t *r);
  		static Handle<Value> GetDeviceInfoSync(const Arguments& args);

  		static Handle<Value> GetDeviceOrientationAsync(const Arguments& args);
		static void GetDeviceOrientationRequestAsync(uv_work_t *r);
		static void GetDeviceOrientationRequestAfterAsync(uv_work_t *r);
  		static Handle<Value> GetDeviceOrientationSync(const Arguments& args);

	public:
  		static void Initialize(Handle<Object> target);
  		static Handle<Value> NewInstance(const Arguments& args);
		HMDDevice* GetDevice();
};

#endif