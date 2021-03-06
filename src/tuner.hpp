/*
    Rocaloid
    Copyright (C) 2015 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/

#ifndef RUCE_TUNER_HPP
#define RUCE_TUNER_HPP

#include <libwintf8/u8str.h>
#include <stdexcept>
#include <cstdint>

namespace RUCE {

/**
 * Conversion among note name, MIDI key ID, and frequency
 */
class Tuner {
public:
    static uint8_t note_name_to_midi_id(const WTF8::u8string &note_name);
    static double midi_id_to_freq(uint8_t midi_id);
    static double midi_id_to_freq(double midi_id);
    static double note_name_to_freq(const WTF8::u8string &note_name) {
        return midi_id_to_freq(note_name_to_midi_id(note_name));
    }
    class TunerError;
};

class Tuner::TunerError : public std::runtime_error {
public:
    TunerError() : std::runtime_error("Invalid note name") {}
};

}

#endif
