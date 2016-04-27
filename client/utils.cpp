/** 
 *   HTTP Chat server with authentication and multi-channeling.
 *
 *   Copyright (C) 2016  Maxim Alov
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software Foundation,
 *   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <chrono>
#include <cstdio>
#include <iostream>
#include "api/api.h"
#include "rapidjson/document.h"
#include "utils.h"

namespace util {

std::string enterSymbolic() {
  printf("Enter name: ");
  std::string name;
  std::cin >> name;
  return name;
}

int selectChannel() {
  printf("Select channel: ");
  int channel = 0;
  std::cin >> channel;
  return channel;
}

uint64_t getCurrentTime() {
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  return millis;
}

bool checkStatus(const std::string& json) {
  rapidjson::Document document;
  document.Parse(json.c_str());
  return document.IsObject() &&
      document.HasMember(ITEM_CODE) && document[ITEM_CODE].IsInt() &&
      document.HasMember(ITEM_ID) && document[ITEM_ID].IsInt64();
}

bool checkSystemMessage(const std::string& json, std::string* system) {
  rapidjson::Document document;
  document.Parse(json.c_str());
  bool result = document.IsObject() &&
         document.HasMember(ITEM_SYSTEM) && document[ITEM_SYSTEM].IsString();
  if (result) {
    *system = document[ITEM_SYSTEM].GetString();
  }
  return result;
}

}

