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

#ifndef CHAT_SERVER_SECURE_CLIENT_API_IMPL__H__
#define CHAT_SERVER_SECURE_CLIENT_API_IMPL__H__

#if SECURE

#include <openssl/bio.h>
#include "api/api.h"

/* Client implementation */
// ----------------------------------------------------------------------------
class SecureClientApiImpl : public ClientApi {
public:
  SecureClientApiImpl(
    BIO* bio,
    const std::string& ip_address,
    const std::string& port);
  virtual ~SecureClientApiImpl();

  /* API */
  void getLoginForm() override;
  void getRegistrationForm() override;
  void sendLoginForm(const LoginForm& form) override;
  void sendRegistrationForm(const RegistrationForm& form) override;
  void sendMessage(const Message& message) override;
  void logout(ID_t id, const std::string& name) override;
  void switchChannel(ID_t id, int channel, const std::string& name) override;

private:
  BIO* m_bio;
  std::string m_host;
};

#endif  // SECURE

#endif  // CHAT_SERVER_SECURE_CLIENT_API_IMPL__H__

