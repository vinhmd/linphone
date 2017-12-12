/*
 * basic-to-client-group-chat-room.h
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _BASIC_TO_CLIENT_GROUP_CHAT_ROOM_H_
#define _BASIC_TO_CLIENT_GROUP_CHAT_ROOM_H_

#include "abstract-chat-room.h"

// =============================================================================

LINPHONE_BEGIN_NAMESPACE

class BasicToClientGroupChatRoomPrivate;
class ChatRoom;

class LINPHONE_PUBLIC BasicToClientGroupChatRoom : public AbstractChatRoom {
public:
	BasicToClientGroupChatRoom (const std::shared_ptr<ChatRoom> &chatRoom);

	const ChatRoomId &getChatRoomId () const override;

	const IdentityAddress &getPeerAddress () const override;
	const IdentityAddress &getLocalAddress () const override;

	time_t getCreationTime () const override;
	time_t getLastUpdateTime () const override;

	State getState () const override;

	std::list<std::shared_ptr<EventLog>> getHistory (int nLast) const override;
	std::list<std::shared_ptr<EventLog>> getHistoryRange (int begin, int end) const override;
	int getHistorySize () const override;

	void deleteHistory () override;

	std::shared_ptr<ChatMessage> getLastChatMessageInHistory () const override;

	int getChatMessageCount () const override;
	int getUnreadChatMessageCount () const override;

	void compose () override;
	bool isRemoteComposing () const override;
	std::list<IdentityAddress> getComposingAddresses () const override;

	std::shared_ptr<ChatMessage> createChatMessage () override;
	std::shared_ptr<ChatMessage> createChatMessage (const std::string &text) override;

	// TODO: Remove LinphoneContent by LinphonePrivate::Content.
	std::shared_ptr<ChatMessage> createFileTransferMessage (const LinphoneContent *initialContent) override;

	std::shared_ptr<ChatMessage> findChatMessage (const std::string &messageId) const override;
	std::shared_ptr<ChatMessage> findChatMessage (
		const std::string &messageId,
		ChatMessage::Direction direction
	) const override;

	void markAsRead () override;

private:
	L_DECLARE_PRIVATE(BasicToClientGroupChatRoom);
	L_DISABLE_COPY(BasicToClientGroupChatRoom);
};

LINPHONE_END_NAMESPACE

#endif // ifndef _BASIC_TO_CLIENT_GROUP_CHAT_ROOM_H_