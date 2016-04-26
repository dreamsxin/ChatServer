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

#ifndef CHAT_SERVER_PEER_DTO__H__
#define CHAT_SERVER_PEER_DTO__H__

#include <string>

class PeerDTO {
public:
  static PeerDTO EMPTY;

  PeerDTO(
    const std::string& login,
    const std::string& email,
    const std::string& password);

  inline const std::string& getLogin() const { return m_login; }
  inline const std::string& getEmail() const { return m_email; }
  inline const std::string& getPassword() const { return m_password; }

private:
  std::string m_login;
  std::string m_email;
  std::string m_password;
};

#endif  // CHAT_SERVER_PEER_DTO__H__
