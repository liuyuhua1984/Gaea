/*
 *  Copyright Beijing 58 Information Technology Co.,Ltd.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */
/*
 * DataReceiver.h
 *
 * Created on: 2011-7-5
 * Author: Service Platform Architecture Team (spat@58.com)
 */

#ifndef DATARECEIVER_H_
#define DATARECEIVER_H_
#include "SocketPool.h"
#include <pthread.h>
#include <map>
namespace gaea {
class DataReceiver {
public:
	static DataReceiver* GetInstance();
	void registerSocket(int fd, SocketPool *socketPool);
	void unRegisterSocket(int fd);
	virtual ~DataReceiver();
	static void socketReadData(void *arg);
	int getEpfd() const;
private:
	DataReceiver();
	static void* epollReadData(void *arg);
	static DataReceiver *dataReceiver;
	static pthread_mutex_t mutex;
	static std::map<int, SocketPool*> *socketMap;
	int epfd;
	pthread_t ntid;
};
}
#endif /* DATARECEIVER_H_ */
