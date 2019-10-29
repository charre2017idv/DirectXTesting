#include "mfCamera.h"



mfCamera::mfCamera()
{
}


mfCamera::~mfCamera()
{
}

void mfCamera::Init(mfCameraDesc _Desc)
{
  m_Eye = XMVectorSet(_Desc.Eye.x, _Desc.Eye.y, _Desc.Eye.z, _Desc.Eye.w);
  m_Up = XMVectorSet(_Desc.Up.x, _Desc.Up.y, _Desc.Up.z, _Desc.Up.w);
  m_Front = XMVectorSet(_Desc.Front.x, _Desc.Front.y, _Desc.Front.z, _Desc.Front.w);
  m_Right = XMVectorSet(_Desc.Right.x, _Desc.Right.y, _Desc.Right.z, _Desc.Right.w);
  m_LookAt = XMVectorSet(_Desc.LookAt.x, _Desc.LookAt.y, _Desc.LookAt.z, _Desc.LookAt.w);
}

void mfCamera::Update()
{
  Render();
  setViewMatrix();
}

void mfCamera::Render()
{
  m_Front = XMVector4Normalize(m_LookAt - m_Eye);
  m_Right = XMVector4Normalize(XMVector3Cross(m_Up, m_Front));
  m_Up = XMVector4Normalize(XMVector3Cross(m_Front, m_Right));
  m_LookAt = m_Front + m_Eye;
}


XMMATRIX  mfCamera::getViewMatrix()
{
  return m_view;
}

XMMATRIX mfCamera::getProjMatrix()
{
  return m_proj;
}


void mfCamera::setViewMatrix()
{
  m_view = XMMatrixLookAtLH(m_Eye, m_LookAt, m_Up);
}

void mfCamera::setProjMatrix(float FoV, int width, int height, float Near, float Far)
{
  m_proj = XMMatrixPerspectiveFovLH(FoV, width / (float)height, Near, Far);
}

void mfCamera::moveLeft()
{
  m_Eye -= m_Right * m_Magnitude;
  m_LookAt -= m_Right * m_Magnitude;

}

void mfCamera::moveRight()
{
  m_Eye += m_Right * m_Magnitude;
  m_LookAt += m_Right * m_Magnitude;

}

void mfCamera::moveUp()
{
  m_Eye += m_Up * m_Magnitude;
  m_LookAt += m_Up * m_Magnitude;
}

void mfCamera::moveDown()
{
  m_Eye -= m_Up * m_Magnitude;
  m_LookAt -= m_Up * m_Magnitude;

}

void mfCamera::moveForward()
{
  m_Eye += m_Front * m_Magnitude;
  m_LookAt += m_Front * m_Magnitude;
}

void mfCamera::moveBack()
{
  m_Eye -= m_Front * m_Magnitude;
  m_LookAt -= m_Front * m_Magnitude;

}

void mfCamera::rotate(POINT* vec)
{
  m_Eye += m_Right * m_lookRotationMagnitude * (vec->x);
  Render();
  m_Eye -= m_Up * m_lookRotationMagnitude * (vec->y);
}



void mfCamera::move(Vector3 * mat)
{
  if (mat->x > 0)
    moveRight();
  if (mat->x < 0)
    moveLeft();
  if (mat->y > 0)
    moveUp();
  if (mat->y < 0)
    moveDown();
  if (mat->z > 0)
    moveForward();
  if (mat->z < 0)
    moveBack();

  Render();
  setViewMatrix();
}