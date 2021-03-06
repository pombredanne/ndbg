// Copyright 2011 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* mythread(void* param) {
  int iter = 0;
  while(true) {
    printf("Thread slave %i\n", iter++);
    sleep(1);
  }
}

int main(int argc, char** argv) {
  pthread_t tid;
  pthread_create(&tid, NULL, mythread, (void*)7);
  int iter = 0;
  while(true) {
    printf("Master thread iter %i.\n", iter++);
    sleep(1);
  }
}
