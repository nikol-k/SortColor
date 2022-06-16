#pragma once

//����� ��������, ����������� �������� �����:
class ColorObject
{
public:
    ColorObject();
    ColorObject(char color);
    void SetColor(char color);
    char GetColor();
private:
    char _color;
};


// ���� �������������:
ColorObject::ColorObject()
{
    _color = 'R';
}
ColorObject::ColorObject(char color)
{
    _color = color;
}


//������ ������:
void ColorObject::SetColor(char color)
{
    _color = color;
}
char ColorObject::GetColor()
{
    return _color;
}
