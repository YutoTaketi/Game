#pragma once
class StageNumber : public IGameObject
{
public:
	StageNumber();
	~StageNumber();
	//�X�e�[�W�̃X�e�[�g��Ԃ�
	static StageNumber& GetInstance()
	{
		static StageNumber stageNo;
		return stageNo;
	}
	//�X�e�\�W�̃X�e�[�g
	enum StageNo {
		enState_Stage1,
		enState_Stage2
	};
	//�X�e�[�W�ԍ����Z�b�g����
	void SetStage(const StageNo& number)
	{
		m_stageNo = number;
	}
	//�X�e�[�W�ԍ���Ԃ�
	StageNo GetStageNumber() const
	{
		return m_stageNo;
	}
	StageNo m_stageNo = enState_Stage1; //�X�e�[�WNo�̏����l
};

