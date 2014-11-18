#pragma once
class EditorHelper
{
public:
	static ShpfileType GetShapeType2D(IShapeEditor* editor);
	static bool IsEmpty(IShapeEditor* editor);
	static bool IsGroupOverlayCursor(tkCursorMode cursorMode);
	static bool IsDigitizingCursor(tkCursorMode mode);
	static void CopyOptionsFrom(IShapeEditor* editor, IShapefile* sf);
	static void CopyOptionsFrom(IShapeEditor* editor, IShapeDrawingOptions* options);
};
