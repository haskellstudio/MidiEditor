#ifndef KEYPRESSUREEVENT_H_
#define KEYPRESSUREEVENT_H_

#include "MidiEvent.h"

#include <QSpinBox>
#include <QWidget>
#include <QLabel>

class KeyPressureEvent : public MidiEvent {

	public:
		KeyPressureEvent(int channel, int value, int note);
		KeyPressureEvent(KeyPressureEvent &other);

		virtual int line();

		QString toMessage();
		QByteArray save();

		virtual ProtocolEntry *copy();
		virtual void reloadState(ProtocolEntry *entry);

		QString typeString();
		void generateWidget(QWidget *widget);
		void editByWidget();

		int value();
		int note();
		void setValue(int v);
		void setNote(int n);

	private:
		int _value, _note;
		static QSpinBox *_val_box, *_note_box;
		static QLabel *_val_label, *_note_label;
		static QWidget *_val_widget, *_note_widget;
};

#endif
