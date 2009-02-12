/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLETRANSPMAPPER_H__
#define __MayaDM_PARTICLETRANSPMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleTranspMapper : public DependNode
{
public:
public:
	ParticleTranspMapper():DependNode(){}
	ParticleTranspMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleTranspMapper"){}
	virtual ~ParticleTranspMapper(){}
	void setParticleTransparency(const float3& pt)
	{
		fprintf(mFile,"\tsetAttr \".pt\" -type \"float3\" ");
		pt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParticleTransparencyR(float ptr)
	{
		if(ptr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pt.ptr\" %f;\n", ptr);

	}
	void setParticleTransparencyG(float ptg)
	{
		if(ptg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pt.ptg\" %f;\n", ptg);

	}
	void setParticleTransparencyB(float ptb)
	{
		if(ptb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pt.ptb\" %f;\n", ptb);

	}
	void getParticleTransparency()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getParticleTransparencyR()
	{
		fprintf(mFile,"\"%s.pt.ptr\"",mName.c_str());

	}
	void getParticleTransparencyG()
	{
		fprintf(mFile,"\"%s.pt.ptg\"",mName.c_str());

	}
	void getParticleTransparencyB()
	{
		fprintf(mFile,"\"%s.pt.ptb\"",mName.c_str());

	}
protected:
	ParticleTranspMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLETRANSPMAPPER_H__