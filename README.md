# ЗАДАНИЕ

## Задание №1
В энергонезависимой памяти хранятся два пароля: публичный пароль для открытия кодового замка и служебный пароль для смены публичного пароля. Служебный пароль неизменен. Длина обоих паролей – 4 цифры.
Ознакомиться с принципами работы клавиатуры (элемент KEYPAD-PHONE в среде Proteus). 
Реализовать систему проверку вводимого пароля. Публичный пароль должен быть введен по маске &ast;хххх, где х – цифра. Правильность ввода пароля сигнализировать с помощью светодиодов (зеленым светодиодом для корректного пароля, красным – для неправильного); соответствующий светодиод должен быть зажжен на 2 секунды. Прервать ввод любого пароля можно нажатием на кнопку #; в этом случае должен быть зажжен желтый индикатор на 2 секунды.
Ознакомиться с принципами работы 4-разрядного 7-сегментного индикатора, отобразить с его помощью вводимые символы. Введенная с помощью клавиатуры k-я цифра пароля должна быть отображена на семисегментном индикаторе в разряде под номером k. 
Реализовать систему смены публичного пароля после ввода служебного пароля. Соответствующую последовательность команд можно представить в виде &ast;yyyyzzzz, где yyyy – служебный пароль, zzzz – новый публичный пароль. После ввода правильного служебного пароля должны быть зажжены все 3 индикатора, они должны находиться во включенном состоянии до окончания ввода нового публичного пароля. После успешного ввода нового публичного пароля должен быть зажжен зеленый индикатор на 2 секунды. В случае отмены изменения публичного пароля (нажатие на кнопку * или # вместо ввода цифры) должен быть зажжен красный индикатор на 2 секунды, а публичный пароль должен остаться без изменений.
Состояния и действия устройства дублировать записью в com-порт (терминал виртуального устройства). Также реализовать возможность установки публичного пароля через виртуальный терминал com-порта.

![Image of project](../images/Picture1.png?raw=true)

## Задание №2
Реализовать устройство генерации периодического импульсного сигнала:
 -	организовать вывод полученного сигнала на экран (осциллограф) и на двухстрочный дисплей (отображение частоты и скважности сигнала);
 -	изменение характеристик сигнала (частота, амплитуда) выполнять с помощью потенциометров в соответствии с вариантом.
Выполнить симуляцию работы устройства в среде Proteus.

## Задание №3
Реализовать устройство взаимодействия контроллера с компьютером по протоколу RS-232. Успешность обработки команды – возврат сообщения «Error» или «Ок». в виртуальный терминал.. В состав устройства входит двухстрочный дисплей (16х2) на котором дублируется полученная команда и результат ее обработки. 
Опционально: выполнить подсчет контрольной суммы успешной команды функцией XOR, которую дописывать к сообщению «ОК». 
Выполнить симуляцию работы устройства в среде Proteus.

## Задание №4
Реализовать устройство взаимодействия контроллера с ЖК дисплеем (Графический дисплей формата 128х64) по интерфейсу SPI. Отобразить на экране эмблему факультета номер группы и фамилию студента. 
Выполнить симуляцию работы устройства в среде Proteus.
